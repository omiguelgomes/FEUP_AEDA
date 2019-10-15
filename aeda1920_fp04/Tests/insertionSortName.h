#include <vector>
#include "parque.h"

using namespace std;

void insertionSortName(vector<InfoCartao> &i)
{
    for (unsigned int p = 1; p < i.size(); p++)
    {
        InfoCartao tmp = i[p];
        int j;
        for (j = p; j > 0 && tmp.nome < i[j-1].nome; j--)
            i[j] = i[j-1];
        i[j] = tmp;
    }
}
