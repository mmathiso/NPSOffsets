#include <iostream>

using namespace std;

array<Double_t, 1080> LoadNPSwfOffsets(Int_t run, string offsetfilename = "./wfOffsets_master.txt", bool verbose = 0) {
    array<Double_t, 1080> offset = {0.};
    const Int_t nBlocks = offset.size();
    
    ifstream offsetfile;
    string word;
    Int_t run1, run2;

    offsetfile.open(offsetfilename);
    if (verbose) cout << "Opened file " << offsetfilename << "\n";

    while(offsetfile.is_open()) {
        offsetfile >> run1 >> word >> run2;
        if(run >= run1 && run <= run2) {
	        for(Int_t i = 0; i < nBlocks; i++) {
	            offsetfile >> offset[i];
	        }
	        cout << "Offsets loaded for run " << run << "\n";
	        break;
        }
        else {
	        for(Int_t i = 0; i < nBlocks; i++) {
	            offsetfile >> word;
	        }
        }

        if(offsetfile.eof()) {
	        cout << "WARNING: UNABLE TO LOAD OFFSETS FOR RUN  " << run << endl;
	        break;
        }
    }

    offsetfile.close();
    if (verbose) cout << "Closed file " << offsetfilename << "\n";

    return offset;
}