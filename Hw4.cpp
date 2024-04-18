#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

// LRU function
void LRU(const vector<int>& pageReferenceString, int numFrames) {
    int pageFaults = 0;
    vector<pair<int, int>> pageVector;
    vector<int> pages;

    cout << "For LRU Algorithm:" << endl;
    for (int i = 0; i < pageReferenceString.size(); ++i) {
        int page = pageReferenceString[i];
        bool pageFound = false;

        // Check if page is already in memory
        for (int j = 0; j < pages.size(); ++j) {
            if (pages[j] == page) {
                // If page is found, remove it and push it to the back (to simulate LRU)
                pages.erase(pages.begin() + j);
                pages.push_back(page);
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            // If page is not in memory, it's a page fault
            pageFaults++;
            cout << "Step " << i + 1 << ": Page fault (" << page << ") - Page Table: {" << page << "}, Frames: [";

            // If frames are full, remove the least recently used page
            if (pages.size() == numFrames) {
                int lruPage = pages[0];
                pages.erase(pages.begin());
                for (int k = 0; k < pageVector.size(); ++k) {
                    if (pageVector[k].first == lruPage) {
                        pageVector.erase(pageVector.begin() + k);
                        break;
                    }
                }
            }

            // Add the new page to memory
            pages.push_back(page);
            pageVector.push_back({page, i}); // Store the page and its reference index

            // Output the current step
            for (int j = 0; j < pages.size(); ++j) {
                cout << pages[j];
                if (j < pages.size() - 1) cout << ", ";
            }
            cout << "], Faults: " << pageFaults << endl;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl << endl;
}

// OPT function
void Optimal(const vector<int>& pageReferenceString, int numFrames) {
    int pageFaults = 0;
    vector<int> frames;
    unordered_set<int> frameSet;

    cout << "For Optimal Algorithm:" << endl;
    for (int i = 0; i < pageReferenceString.size(); ++i) {
        int page = pageReferenceString[i];
        bool pageFound = (frameSet.find(page) != frameSet.end());

        if (!pageFound) {
            // If page is not in memory, it's a page fault
            pageFaults++;
            cout << "Step " << i + 1 << ": Page fault (" << page << ") - Page Table: {" << page << "}, Frames: [";

            // If frames are full, find the page that will be used farthest in the future
            if (frames.size() == numFrames) {
                int farthestIndex = -1;
                int farthestPage = -1;
                for (int j = 0; j < frames.size(); ++j) {
                    int nextPage = frames[j];
                    int nextIndex = i + 1;
                    while (nextIndex < pageReferenceString.size()) {
                        if (pageReferenceString[nextIndex] == nextPage) {
                            if (nextIndex > farthestIndex) {
                                farthestIndex = nextIndex;
                                farthestPage = nextPage;
                            }
                            break;
                        }
                        nextIndex++;
                    }
                    if (nextIndex == pageReferenceString.size()) {
                        farthestPage = nextPage;
                        break;
                    }
                }
                frameSet.erase(farthestPage);
                frames.erase(find(frames.begin(), frames.end(), farthestPage));
            }

            // Add the new page to memory
            frameSet.insert(page);
            frames.push_back(page);

            // Output the current step
            for (int j = 0; j < frames.size(); ++j) {
                cout << frames[j];
                if (j < frames.size() - 1) cout << ", ";
            }
            cout << "], Faults: " << pageFaults << endl;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl << endl;
}

// FIFO function
void FIFO(const vector<int>& pageReferenceString, int numFrames) {
    int pageFaults = 0;
    queue<int> pageQueue;
    unordered_set<int> pageSet;

    cout << "For FIFO Algorithm:" << endl;
    for (int i = 0; i < pageReferenceString.size(); ++i) {
        int page = pageReferenceString[i];

        // If page is not in the set, it's a page fault
        if (pageSet.find(page) == pageSet.end()) {
            pageFaults++;
            cout << "Step " << i + 1 << ": Page fault (" << page << ") - Page Table: {" << page << "}, Frames: [";

            // If frames are full, remove the oldest page
            if (pageQueue.size() == numFrames) {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(oldestPage);
                cout << oldestPage << " (removed), ";
            }

            // Add the new page to the set and the queue
            pageSet.insert(page);
            pageQueue.push(page);
            cout << page << " (added)], Faults: " << pageFaults << endl;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <page_reference_string> <num_frames>" << endl;
        return 1;
    }

    // Parse input
    string pageReferenceStringStr = argv[1];
    int numFrames;
    istringstream iss(argv[2]);
    if (!(iss >> numFrames)) {
        cerr << "Invalid number of frames" << endl;
        return 1;
    }

    // Parse page reference string
    vector<int> pageReferenceString;
    istringstream ss(pageReferenceStringStr);
    string token;
    while (getline(ss, token, ',')) {
        int page;
        istringstream(token) >> page;
        pageReferenceString.push_back(page);
    }

    // Output simulation results for LRU algorithm
    LRU(pageReferenceString, numFrames);

    // Output simulation results for Optimal algorithm
    Optimal(pageReferenceString, numFrames);

    // Output simulation results for FIFO algorithm
    FIFO(pageReferenceString, numFrames);

    return 0;
}

// g++ hw4.cpp -o hw4
// hw4 "1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5" 4