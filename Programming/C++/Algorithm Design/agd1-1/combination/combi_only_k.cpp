#include <iostream>
#include <vector>


using namespace std;


void combi_kn(                      //* Generate combination of k elements from n elements
    vector<int> &sol,               //? 2 from 4 (1 2 3 4)
    int len, 
    int n, 
    int k, 
    int chosen
) {  

    if (len < n) { 
        if (len - chosen < n - k) {         

            //* len - chosen = Number of elements we have NOT choose yet (len - "1")
            //* n - k        = Maximum number of elements we are allowed to not choose  (opposide of k)

            sol[len] = 0;                      
            combi_kn(sol, len + 1, n, k, chosen);

        }
        if (chosen < k) {           //! Prevent using more than k elements

            sol[len] = 1;
            combi_kn(sol, len + 1, n, k, chosen + 1);   

        }

    } else {

        for (int i = 0; i < n; i++) {       
            if (sol[i] == 1) {             
                cout << i + 1 << "";
            }
        }
        cout << "}" << '\n';                
    }

}


int main() {

    vector<int> sol(4);         
    combi_kn(sol, 0, 4, 2, 0);           

}