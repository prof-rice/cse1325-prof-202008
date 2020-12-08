#include "mainwin.h"
#include <iostream>
#include <thread>
#include "mandelbrot.h"

int main (int argc, char* argv[])  {
    // Specify default image size, iteration count, and filename 
    // Usually, width == height to avoid distortion
    // Higher iteration counts (up to 255) increase resolution
    int width = 1000;
    int height = 1000;
    int icount = 60;
    int nthreads = 1;
    bool pool = true;
    bool shuffle = false;
    
    // Parse the command line, overwriting defaults as needed
    try {
        if(argc > 1 && !strcmp(argv[1], "-h")) {
            std::cerr << "usage: " << argv[0] << " [width [height [icount [nthreads [pool [shuffle]]]]]]"
                << "\n  width x height is the size of the image in pixels (default " << width << 'x' << height
                << ")\n  icount is the resolution of pixels (default " << icount
                << ")\n  nthreads is number of threads (default " << nthreads
                << ")\n  pool is 1 for thread pool or 0 for y range allocation (default " << pool
                << ")\n  shuffle is 1 to solve rows in random order, 0 in sequence (default " << shuffle
                << ")\n";
            return 0;
        }
        if(argc > 1) width  = std::atoi(argv[1]);
        if(argc > 2) height = std::atoi(argv[2]);
        else height = width;
        if(argc > 3) icount = std::atoi(argv[3]);
        if(argc > 4) nthreads = std::atoi(argv[4]);
        if(argc > 5) pool = (std::atoi(argv[5]) != 0);
        if(argc > 6) shuffle = (std::atoi(argv[6]) != 0);
    } catch(std::exception& e) {
        std::cerr << "Invalid arguments: -h for usage\n";
        return -2;
    }
    
    // Show the image to be generated
    std::cout << "\n\n  width: " << width 
              << "  height: " << height
              << "  icount: " << icount 
              << "  threads: " << nthreads
              << ((pool==1) ? "  1-pool" : "  0-range")
              << ((shuffle==1) ? "  1-shuffled" : "  0-sequence")
              << std::endl;
    
    // Instance a Mandelbrot fractal
    Mandelbrot m{width, height, icount, nthreads, pool, shuffle};
    
    // Instance the main window (gtkmm aborts if argc > 1)
    argc = 1;
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.paint");
    Mainwin win{width, height};
    
    // Sleep for a second or more, then start generating the points.  We must use a separate
    //  thread for this, because once gtkmm gets our main thread, it holds it until the main
    //  window is closed. We wait one second to allow the main window to begin running.
    //
    // (This is poor coding, btw, as it assumes the gtkmm window will be running within a second.
    //  A better design would use a FIFO queue to store pixels until the gtkmm window is ready
    //  to display them. Unfortunately, std::queue is NOT thread-safe - really??? - and writing 
    //  a thread-safe queue version is too complex for this assignment. So we'll grit our teeth
    //  anduse the "wait a second" hack. Do NOT do this for production code, though!)
    std::thread t([&m, &win] {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m.generate(win.canvas());
    });
    
    // Run the GUI
    int result = app->run(win);
    
    // Join the Mandelbrot calculation thread back to the main thread
    t.join();
    
    // Return the GUI result to the OS
    return result;
}
