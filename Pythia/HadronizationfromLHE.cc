
// to run
// ./HadronizationfromLHE HadronizationfromLHE.cmnd HadronizationfromLHEout.hepmc > out

#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h"

using namespace Pythia8;


int main(int argc, char* argv[]) {
 
// Check that correct number of command-line arguments
if (argc != 3) {
  cerr << " Unexpected number of command-line arguments. \n You are"
       << " expected to provide one input and one output file name. \n"
       << " Program stopped! " << endl;
  return 1;
  }
  
// Check that the provided input name corresponds to an existing file.
ifstream is(argv[1]);
if (!is) {
  cerr << " Command-line file " << argv[1] << " was not found. \n"
       << " Program stopped! " << endl;
  return 1;
 }
  
// Confirm that external files will be used for input and output.
cout << "\n >>> PYTHIA settings will be read from file " << argv[1]
     << " <<< \n >>> HepMC events will be written to file "
     << argv[2] << " <<< \n" << endl;


// Interface for conversion from Pythia8::Event to HepMC event.
HepMC::Pythia8ToHepMC ToHepMC;
  
// Specify file where HepMC events will be stored.
HepMC::IO_GenEvent ascii_io(argv[2], std::ios::out);
 
// Generator.
Pythia pythia;
 
// Read in commands from external file.
pythia.readFile(argv[1]);



// Read from an LHE file
pythia.readString("Beams:frameType = 4");
pythia.readString("Beams:LHEF = ejemplo_hadronizar.lhe");


// Extract settings to be used in the main program.
int nEvent = pythia.mode("Main:numberOfEvents");
//int nAbort    = pythia.mode("Main:timesAllowErrors");


//pythia.readString("ProcessLevel:all = off");

pythia.init();

int iAbort = 0;
for (int iEvent = 0; iEvent < nEvent; ++iEvent) {


// Generate event.
   if (!pythia.next()) {
  
        // If failure because reached end of file then exit event loop.
        if (pythia.info.atEndOfFile()) {
          cout << " Aborted since reached end of Les Houches Event File\n";
          break;
        }
  
        // First few failures write off as "acceptable" errors, then quit.
        if (++iAbort < 100) continue;
        cout << " Event generation aborted prematurely, owing to error!\n";
        break;
        }


// Construct new empty HepMC event and fill it.
// Units will be as chosen for HepMC build; but can be changed
// by arguments, e.g. GenEvt( HepMC::Units::GEV, HepMC::Units::MM)
HepMC::GenEvent* hepmcevt = new HepMC::GenEvent();
ToHepMC.fill_next_event( pythia, hepmcevt );

// Write the HepMC event to file. Done with it.
ascii_io << hepmcevt;
delete hepmcevt;

  
// End of event loop. Statistics. Histogram.
}
pythia.stat();
 
// Done.
return 0;
}


