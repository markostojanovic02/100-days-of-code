#include <iostream>

//Function that for given letter returns it's position in  alphabet
int alphabetPos(char letter)
{
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] == letter)
            return i;
    }
}

int main()
{
    //Initialization and input
    int noDots = 3;
    std::cout << "Number of dots: ";
    std::cin >> noDots;

    std::cout << "Coordinates for each dot:\n";
    int x[noDots];
    int y[noDots];
    for (int i = 0; i < noDots; ++i) {
        std::cin >> x[i] >> y[i];
    }

    //Adding edges
    int noEdges = 3;
    std::cout << "Number of edges: ";
    std::cin >> noEdges;
    std::cout << "Edge start and edge end (type uppercase letters, 'A' being first dot you entered, 'B' second etc.):\n";
    char edgeStart[noEdges] = {'A', 'B', 'C'};
    char edgeStop[noEdges] = {'B', 'C', 'A'};
    for (int i = 0; i < noEdges; ++i) {
        std::cin >> edgeStart[i] >> edgeStop[i];
    }

    //Printing out original edges
    std::cout << "\nOriginal edges:\n";
    for (int i = 0; i < noEdges; ++i) {
        std::cout << edgeStart[i] << "(" << x[alphabetPos(edgeStart[i])] << "," << y[alphabetPos(edgeStart[i])]
        << ")" << " - " << edgeStop[i] << "(" << x[alphabetPos(edgeStop[i])] << "," << y[alphabetPos(edgeStop[i])] << ")\n";
    };

    //Swapping positions in edges
    for (int i = 0; i < noEdges; ++i) {
        int temp = edgeStart[i];
        edgeStart[i] = edgeStop[i];
        edgeStop[i] = temp;
    }

    //Printing out modified edges
    std::cout << "\nNew edges:\n";
    for (int i = 0; i < noEdges; ++i) {
        std::cout << edgeStart[i] << "(" << x[alphabetPos(edgeStart[i])] << "," << y[alphabetPos(edgeStart[i])]
        << ")" << " - " << edgeStop[i] << "(" << x[alphabetPos(edgeStop[i])] << "," << y[alphabetPos(edgeStop[i])] << ")\n";
    };
}
