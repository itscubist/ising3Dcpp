void ising3Dfit(std::string taskdir) {
	gStyle->SetOptFit(1111);
	std::string task3 = "./"+taskdir+"/task3.out";
	std::string task2low = "./"+taskdir+"/task2_0p9.out";
	std::string task2high = "./"+taskdir+"/task2_1p1.out";
	cout << task3  << endl;
	using namespace std;
	// Read Data
	ifstream tread(task3);
	string lines;
	const int T3LEN = 9, T2LLEN = 4, T2HLEN = 4;
	double resTask3[T3LEN];
	double resTask2low[T2LLEN];
	double resTask2high[T2HLEN];
	double errTask3[T3LEN];
	double errTask2low[T2LLEN];
	double errTask2high[T2HLEN];
	double lenTask3[T3LEN];
	double lenTask2low[T2LLEN];
	double lenTask2high[T2HLEN];
	double dummyL, dummyRes, dummyErr;
	int ctr = 0;
	while(tread.good()) {
		tread >> dummyL >> dummyRes >> dummyErr;
		if(ctr < T3LEN) {
			resTask3[ctr] = dummyRes;
			errTask3[ctr] = dummyErr;
			lenTask3[ctr] = dummyL;
			cout << resTask3[ctr] << " " << errTask3[ctr] << " " << lenTask3[ctr] << endl;
			ctr++;
		}
	}
	tread.close();
	ctr = 0;
	tread.open(task2low);
	while(tread.good()) {
		tread >> dummyL >> dummyRes >> dummyErr;
		cout << dummyL << " " << dummyRes << " " << dummyErr << endl;
		if(ctr < T2LLEN) {
			resTask2low[ctr] = dummyRes;
			errTask2low[ctr] = dummyErr;
			lenTask2low[ctr] = dummyL;
			ctr++;
		}
	}
	tread.close();
	ctr = 0;
	tread.open(task2high);
	while(tread.good()) {
		tread >> dummyL >> dummyRes >> dummyErr;
		cout << dummyL << " " << dummyRes << " " << dummyErr << endl;
		if(ctr < T2HLEN) {
			resTask2high[ctr] = dummyRes;
			errTask2high[ctr] = dummyErr;
			lenTask2high[ctr] = dummyL;
			ctr++;
		}
	}
	tread.close();
	TF1 ftask3("ftask3","[0]*x**(2-[1])",10,101);
	ftask3.SetParameter(1,0.03627);
	ftask3.SetParNames("C_{2}","#eta");
	TF1 ftask2high("ftask2high","[0]*x**[1]",10,101);
	ftask2high.SetParNames("C_{0}","Power");
	ftask2high.SetParameter(1,3);
	TF1 ftask2low("ftask2low","[0]",10,101);
	ftask2low.SetParNames("C_{1}");

	TGraphErrors* gtask3 = new TGraphErrors(T3LEN,lenTask3,resTask3,NULL,errTask3);
	TGraphErrors* gtask2high = new 
		TGraphErrors(T2HLEN,lenTask2high,resTask2high,NULL,errTask2high);
	TGraphErrors* gtask2low = new 
		TGraphErrors(T2LLEN,lenTask2low,resTask2low,NULL,errTask2low);
	gtask3->Fit("ftask3","");
	gtask2high->Fit("ftask2high","");
	gtask2low->Fit("ftask2low","");
	
	TCanvas* canny1 = new TCanvas("canny1","canny1",1600,2000);
	TCanvas* canny2 = new TCanvas("canny2","canny2",1600,2000);
	TCanvas* canny3 = new TCanvas("canny3","canny3",1600,2000);
	//canny1->SetLogy();
	//canny1->SetLogx();
	canny1->cd();
	gtask3->SetTitle("At J#beta_{critical}");
	gtask3->GetXaxis()->SetTitle("Lattice Points (unitless)");
	gtask3->GetYaxis()->SetTitle("Spin Susceptibility (unitless)");
	gtask3->SetMarkerSize(1);
	gtask3->SetMarkerStyle(20);
	gtask3->Draw("AP");
	canny2->cd();
	//canny2->SetLogy();
	//canny2->SetLogx();
	gtask2high->SetTitle("At 1.1J#beta_{critical}");
	gtask2high->GetXaxis()->SetTitle("Lattice Points (unitless)");
	gtask2high->GetYaxis()->SetTitle("Spin Susceptibility (unitless)");
	gtask2high->SetMarkerSize(1);
	gtask2high->SetMarkerStyle(20);
	gtask2high->Draw("AP");
	canny3->cd();
	//canny->cd(3)->SetLogy();
	//canny->cd(3)->SetLogx();
	gtask2low->SetTitle("At 0.9J#beta_{critical}");
	gtask2low->GetXaxis()->SetTitle("Lattice Points (unitless)");
	gtask2low->GetYaxis()->SetTitle("Spin Susceptibility (unitless)");
	gtask2low->SetMarkerSize(1);
	gtask2low->SetMarkerStyle(20);
	gtask2low->Draw("AP");
}
