#include <iostream>
using namespace std;

char *search(char list[], char target){
    char *ptr = list;
    while (*ptr != '\0'){
            if (*ptr == target){
                return ptr;
            }
            else{
                ptr++;
            }
    }
    return nullptr;
};

char *Foo(){
    //char c = 'A'; // The address is not guaranteed, it might be freed up in some time
    //char *cptr = &c;  // The address is not guaranteed, it might be freed up in some time
    char *cptr = new char;  // new char is guranteed
    *cptr = 'A';
    return cptr;
}

void Bar(){
    char c = '%';
}

int main(){
    
    int *n = new int;    // Preseve sizeof(int), 4 bytes, for usage after running program. Save address in n.
    // We access the dynamic address using the pointer n.
    // n is statically allocated (at compile time)
    // an unnamed variable is dynamically allocated (at runtime)

    *n = 10;

    int *o = nullptr;
    o = new int;

    *o = 13;

    int sum = *n + *o;

    cout << "Sum: " << sum << endl;

    delete n;
    delete o;

    int size;

    cout << "Enter the size of array: " << endl;
    cin >> size;

    /*int *aptr = new int;
    *aptr = size;
    int array[*aptr] = {};*/

    int *aptr = new int[size];

    for (int i = 0; i < size; i++){
        int input;
        cout << "Enter elements of aptr[" << i << "] (int):" << endl;
        cin >> input;
        aptr[i] = input;
    };

    cout << "The elements in the array are: " << endl;
    for (int i = 0; i < size; i++){
        cout << aptr[i] << endl;
    };

    delete [] aptr; // Delete all elements instead of just one

    char list[] = "French";
    char *targetPtr = search(list, 'c');
    cout << "targetPtr: " << targetPtr << endl;  // Prints the content of the pointer (for pointers pointing to char)
    cout << "Address of target: " << static_cast<void*>(targetPtr) << endl;

    return 0;
}