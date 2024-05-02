#include <iostream>
#define MAX 10
using namespace std;
class Hash
{
    struct node
    {
        int song_id;
        string song_name, singer, track, album;
        struct node *next;
    };
    node *ht[MAX];

public:
    Hash()
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            ht[i] = NULL;
        }
    }
    void display();
    void insert();
    void deleter();
    void search();
};
void Hash::display()
{
    int i;
    node *ptr;

    cout << "\nMusic Library"
         << "\n";
    cout << "Index"
         << "\t"
         << "SongID"
         << "\t"
         << "Singer"
         << "\t"
         << "Song name"
         << "\t"
         << "Track"
         << "\t"
         << "Album"
         << "\n";
    for (i = 0; i < MAX; i++)

    {
        ptr = ht[i];
        cout << "\n"
             << i << "::\t";

        while (ptr != NULL)
        {
            cout << ptr->song_id << "\t";
            cout << ptr->singer << "\t";
            cout << ptr->song_name << "\t";
            cout << ptr->track << "\t";
            cout << ptr->album << "\t";
            ptr = ptr->next;
        }
    }
}
void Hash::insert()
{
    int key, addr;
    struct node *ptr, *temp;
    temp = new node;
    cout << "Enter Song id" << endl;
    cin >> temp->song_id;
    cout << "Enter singer name" << endl;
    cin >> temp->singer;
    cout << "Enter Song name" << endl;
    cin >> temp->song_name;
    cout << "Enter Song track" << endl;
    cin >> temp->track;
    cout << "Enter Song album" << endl;
    cin >> temp->album;
    addr = temp->song_id % MAX;
    temp->next = NULL;

    if (ht[addr] == NULL)
    {
        ht[addr] = temp;
    }
    else
    {
        ptr = ht[addr];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        cout << addr;
    }
}
void Hash::search()
{
    int key, addr;
    struct node *ptr, temp;
    cout << "Enter song id to search" << endl;
    cin >> key;
    addr = key % MAX;
    ptr = ht[addr];
    while (ptr != NULL && key != ptr->song_id)
    {
        ptr = ptr->next;
    }
    if (ptr->song_id == key)
    {
        cout << "Song Found at location :" << addr << endl;
        cout << ptr->song_id << "\t";
        cout << ptr->singer << "\t";
        cout << ptr->song_name << "\t";
        cout << ptr->track << "\t";
        cout << ptr->album << "\t";
    }
}
void Hash::deleter()
{
    int key, addr;
    struct node *ptr, *temp, *prev;
    cout << "Enter song id to delete" << endl;
    cin >> key;
    addr = key % MAX;
    prev = ptr = ht[addr];
    if (key == ptr->song_id)
    {
        prev = prev->next;
        ht[addr] = prev;
        delete (ptr);
    }
    else
    {
        while (ptr != NULL && key != ptr->song_id)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->song_id == key)
        {
            prev->next = ptr->next;
            delete (ptr);
        }
    }
}
int main()
{
    Hash h;
    int ch;
    while (1)
    {
        cout << "\nMusic Library System" << endl;
        cout << "1.Insert  Song Details" << endl;
        cout << "2.Display  Song Details" << endl;
        cout << "3.Search  Song Details" << endl;
        cout << "4. Delete Song Details" << endl;
        cout << "Enter Your choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.display();
            break;
        case 3:
            h.search();
            break;
        case 4:
            h.deleter();
            break;
        default:
            cout << "wrong choice";
        }
    }
}

/* sudo code for assignment 5*/
/**#include <iostream>
#define MAX 10
using namespace std;
class Hash
{
    struct node
    {
        int rollno;
        char name[20];
        struct node *next;
    };
    node *ht[MAX];

public:
    Hash()
    {
        int i;

        for (i = 0; i < MAX; i++)
        {

            ht[i] = NULL;
        }

    }
        void insert();
        void search();
        void deleter();
        void display();
};
void Hash::display()
{
    struct node *ptr;
    int i;
    cout << "Index\t"
         << "Name and Roll no\n";
    for (i = 0; i < MAX; i++)
    {
        ptr = ht[i];
        cout << "\n " << i << "::\t";
        while (ptr != NULL)
        {
            cout << ptr->name << "\t";
            cout << ptr->rollno << "\t";
            ptr = ptr->next;
        }
    }
}
void Hash::insert()
{

    int key, addr;
    struct node *ptr, *temp;
    temp = new node;
    cout << "Enter name" << endl;
    cin >> temp->name;
    cout << "Enter rollno" << endl;
    cin >> temp->rollno;
    addr = temp->rollno % MAX;
    temp->next = NULL;
    if (ht[addr] == NULL)
    {
        ht[addr] = temp;
    }
    else
    {
        ptr = ht[addr];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        cout << addr;
    }
}
void Hash::search()
{
    int key, addr;
    struct node *ptr;
    cout << "Enter roll no to search" << endl;
    cin >> key;
    addr = key % MAX;
    ptr = ht[addr];
    while (ptr != NULL && key != ptr->rollno)
    {
        ptr = ptr->next;
    }
    if (ptr->rollno == key)
    {
        cout << ptr->rollno << "key found at location::" << addr << endl;
    }
}
void Hash::deleter()
{
    int key, addr;
    struct node *temp, *ptr, *prev;
    cout << "Enter roll nom delete" << endl;
    cin >> key;
    addr = key % MAX;
    prev = ptr = ht[addr];
    if (key == ptr->rollno)
    {
        prev = prev->next;
        ht[addr] = prev;
        delete (ptr);
    }
    else
    {
        while (ptr != NULL && key != ptr->rollno)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (key == ptr->rollno)
        {
            prev->next = ptr->next;
            delete (ptr);
        }
    }
}
int main()
{
    Hash h;
    int ch;
    while (1)
    {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Display" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.search();
            break;
        case 3:
            h.deleter();
            break;
        case 4:
            h.display();
        default:
            cout << "\nEnter correct option\n";
        }
    }
}**/