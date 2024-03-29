#ifndef RUNWAYRESERVER_H
#define RUNWAYRESERVER_H
#import <vector>
using namespace std;

/*
RunwayReserver is the main entry point to the Runway Reservation System.
Our aim is to implement the same interface with multiple data structures
to compare and contrast.

v1 will ignore inheritance for now, but we will later want to look at
subclassing a virtual RRS with for example VectorRRS, BSTRRS, etc.

we are treating time as a double -- presumably it is in minutes.
*/

class RunwayReserver {
    static const bool DEBUG = false; //true;
    public:
        /** Default constructor */
        RunwayReserver() {
            // internal storage
            vector<Plane> planes();
            // default landing window k is 3.0 minutes
            m_landingWindow = 3.0;
        }
        /** Default destructor */
        ~RunwayReserver() {
        }

        /** Access m_landingWindow
         * \return The current value of m_landingWindow
         */
        double GetlandingWindow() { return m_landingWindow; }
        /** Set m_landingWindow
         * \param val New value to set
         */
        void SetlandingWindow(double val) {
            if (val > 0) {
                    m_landingWindow = val;
            }
        }

        // Defined interface of a RRS -- add plane, delete plane, lookup plane
        bool add(Plane p, double t) {
            // add plane p in order at time t
            // return true if successful, false otherwise
            p.SetlandingTime(t);
            //add plane to internal vector
            m_planes.push_back(p);
            //update plane's internal time
            //p.SetlandingTime(t);
            //in debug mode, check RI each time
            if (DEBUG) {
                bool check = checkRI();
                if (!check) {
                    cout << "Error: Representational Invariant is FALSE\n";
                    //NOTE: plane's landing time is possibly invalid
                    return false;
                }
            }
            return false; // unimplemented
        }

        bool remove(double t) {
            // remove plane at time t
            // return true if successful, false otherwise
            // set plane's internal time to 0
            //TODO: if p exists, p.SetlandingTime(0)
            return false; // unimplemented
        }

        Plane* lookup(double t) {
            // find plane at time t if it exists, nullptr otherwise
            for (auto plane: m_planes) {
                if (plane.GetlandingTime() == t) {
                    cout << "plane " << plane.Getcallsign() << " found at t=" << t << endl;
                    return &plane; //reference pointer
                }
            }
            return nullptr; // unimplemented
        }

    protected:

    private:
        double m_landingWindow; //!< Member variable "m_landingWindow"
        vector<Plane> m_planes;
        bool checkRI() {
            // Check Representational Invariant
            // (assert that the data structure is still valid)
            // when debugging, we should do this after every update (add/remove)
            //TODO
            double last_time = 0.0;
            for (auto plane : m_planes) {
                double current_time = plane.GetlandingTime();
                cout << plane.Getcallsign() << " " << current_time << endl;
                if ((current_time < last_time) {
                    cout << "RI invalid -- planes not sorted\n";
                    return false;
                }
                else {
                    last_time = current_time;
                }
            }
            return false; // unimplemented
        }
};

#endif // RUNWAYRESERVER_H
