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
class RunwayReserver
{
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
            return false; // unimplemented
        }

        bool remove(double t) {
            // remove plane at time t
            // return true if successful, false otherwise
            return false; // unimplemented
        }

        Plane* lookup(double t) {
            // find plane at time t if it exists, nullptr otherwise
            return nullptr; // unimplemented
        }

        bool checkRI() {
            // Check Representational Invariant
            // (assert that the data structure is still valid)
            // when debugging, we should do this after every update (add/remove)
            return false; // unimplemented
        }

    protected:

    private:
        unsigned int m_landingWindow; //!< Member variable "m_landingWindow"
};

#endif // RUNWAYRESERVER_H
