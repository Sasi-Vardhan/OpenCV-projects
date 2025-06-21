#include "mouseLoc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

cv::Point mousePos(-1, -1);  // global to store current pointer

void mouseCallback(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_MOUSEMOVE) {
        mousePos = Point(x, y);
    }
}

void findCo_ordinates(const std::string &path) {
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
        cerr << "Failed to load image: " << path << endl;
        return;
    }

    string windowName = "Mouse Co-ordinates";
    namedWindow(windowName);
    setMouseCallback(windowName, mouseCallback, nullptr);

    while (true) {
        cv::Mat display = img.clone();  // draw on a fresh copy every frame

        if (mousePos.x >= 0 && mousePos.y >= 0) {
            // Draw circle under pointer
            circle(display, mousePos, 5, Scalar(0, 255, 0), FILLED);

            // Print coordinates
            string text = "X: " + to_string(mousePos.x) + " Y: " + to_string(mousePos.y);
            putText(display, text, Point(mousePos.x + 10, mousePos.y - 10),
                    FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 1);
        }

        imshow(windowName, display);

        int key = waitKey(1);
        if (key == 27) break;  // ESC to exit
    }

    destroyWindow(windowName);
}
