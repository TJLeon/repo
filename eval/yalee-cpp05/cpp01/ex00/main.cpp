#include "zombie.hpp"

using namespace std;

int main()
{
    string input;
    cout << "Stack memory gets freed automatically st the end of scope" << endl;
    cout << "Scopes are components in the code marked by { and }. " << endl;
    cout << "Scope starts at { and ends at }" << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "Now lets try creating an zombie and store it on stack memory." << endl;
    cout << "( Press enter to continue )" << endl;
    cout << "randomChump('qiqi);" << endl;
    getline(cin, input);
    randomChump("qiqi");
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "Since randomChump ends right after the announce function aka the code hits the end of the bracket," << endl;
    cout << "The destructor is called automatically. " << endl;
    cout << "It works the same for while loops and other scopes as well. " << endl;
    cout << "As long as there is a curly bracket, there is a scope. " << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "Now lets try messing with the heap memory. " << endl;
    cout << "Heap memory gives the usser full control on how the object is manipulated. " << endl;
    cout << "Meaning that the user has to free the allocated memory after it served its purpose. " << endl;
    cout << "similar to c, the keyword new is used to allocate memory, and delete is used to free memory. " << endl;
    cout << "A variable has to be declared to store an object in heap memory. " << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "lets now create a zombie in heap memory. " << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "Zombie* z1; " << endl;
    cout << "z1 = newZombie('qiqi')" << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    Zombie* z1;
    z1 = newZombie("qiqi");
    z1->announce();
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "As you can see, no destructor is called even after leaving the function. " << endl;
    cout << "And we can pass this object anywhere we want. " << endl;
    cout << "Now lets manually delete it. " << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    cout << "delete z1;" << endl;
    cout << "( Press enter to continue )" << endl;
    getline(cin, input);
    delete z1;
    cout << "now the object is freed from the heap. " << endl;
}