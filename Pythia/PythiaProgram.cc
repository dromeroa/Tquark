
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



}
