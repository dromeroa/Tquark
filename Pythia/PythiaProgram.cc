
#include "Pythia8/Pythia.h"

using namespace Pythia8;
  
int main() {

// Generator. Shorthand for the event. 
Pythia pythia;
Event& event = pythia.event;

// Read in commands from external file.
pythia.readFile("PythiaProgram.cmnd");

// Extract settings to be used in the main program.
int nEvent = pythia.mode("Main:numberOfEvents");

// Interface for conversion from Pythia8::Event to HepMC event.
HepMC::Pythia8ToHepMC ToHepMC;
  
// Specify file where HepMC events will be stored.
HepMC::IO_GenEvent ascii_io("PythiaProgram.hepmc", std::ios::out);

// Begin event loop. Generate event. Skip if error.
for (int iEvent = 0; iEvent < 100; ++iEvent) {
      if (!pythia.next()) continue;


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






