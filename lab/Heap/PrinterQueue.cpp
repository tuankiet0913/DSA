class PrinterQueue
{
    // your attributes
    vector<pair<int, string>> printQueue;
public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        if (printQueue.empty()) {
            printQueue.push_back(make_pair(priority, fileName));
            return;
        }
        size_t insi = 0; // idx to insert new request
        while (insi < printQueue.size())
        {
            if (printQueue[insi].first < priority) {
                break;
            }
            insi++;
        }
        printQueue.insert(printQueue.begin() + insi, make_pair(priority, fileName));
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        if (printQueue.empty()) {
            cout << "No file to print\n";
            return;
        }
        cout << printQueue[0].second << "\n";
        printQueue.erase(printQueue.begin());
    }
};
