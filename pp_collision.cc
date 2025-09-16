#include "Pythia8/Pythia.h"
#include <iostream>
#include <fstream>

using namespace Pythia8;

int main() {
    Pythia pythia;

    pythia.readString("Beams:idA = 2212");          // proton
    pythia.readString("Beams:idB = 2212");          // proton
    pythia.readString("Beams:eA   = 5.0");          // GeV
    pythia.readString("Beams:eB   = 5.0");          // GeV
    pythia.readString("Beams:frameType = 2");       // fixed target
    pythia.readString("HardQCD:all = on");          // hard-QCD subprocesses

    pythia.init();

    std::ofstream outFile("pp_collision.csv");
    outFile
        << "event,id,status,pt,eta,phi,e,px,py,pz,m,theta,y,"
        << "isCharged,charge,isHadron,isFinal,isVisible,isResonance,"
        << "isLepton,isQuark,isGluon,mother1,mother2,daughter1,daughter2\n";

    // ------------------------------------------------------------------
    // EVENT LOOP  (10000 events)
    // ------------------------------------------------------------------
    const int N_EVENTS_TOTAL  = 10000;
    const int N_EVENTS_PRINT  = 1000;  

    for (int iEvent = 0; iEvent < N_EVENTS_TOTAL; ++iEvent) {
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); ++i) {
            const Particle& p = pythia.event[i];

            // First 1000 events
            if (iEvent < N_EVENTS_PRINT) {
                std::cout << "Event " << iEvent
                          << "  ID: "   << p.id()
                          << "  status: " << p.status()
                          << "  pT: "   << p.pT()
                          << "  eta: "  << p.eta()
                          << "  phi: "  << p.phi()
                          << "  E: "    << p.e()
                          << "  charge: " << p.charge()
                          << "\n";
            }
            outFile << iEvent << ','
                    << p.id()        << ','
                    << p.status()    << ','
                    << p.pT()        << ','
                    << p.eta()       << ','
                    << p.phi()       << ','
                    << p.e()         << ','
                    << p.px()        << ','
                    << p.py()        << ','
                    << p.pz()        << ','
                    << p.m()         << ','
                    << p.theta()     << ','
                    << p.y()         << ','
                    << p.isCharged() << ','
                    << p.charge()    << ','
                    << p.isHadron()  << ','
                    << p.isFinal()   << ','
                    << p.isVisible() << ','
                    << p.isResonance() << ','
                    << p.isLepton()  << ','
                    << p.isQuark()   << ','
                    << p.isGluon()   << ','
                    << p.mother1()   << ','
                    << p.mother2()   << ','
                    << p.daughter1() << ','
                    << p.daughter2()
                    << '\n';
        }
    }

    outFile.close();
    pythia.stat();
    return 0;
}
