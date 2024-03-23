#include <iostream>
#include <string>
using namespace std;


struct Track {
    string title;
    string artist;
    string album;
    string genre;
    string duration;
    int release_year;
   

    Track *next ; 
};


Track* createTrack() {
    Track* newTrack = new Track;
    newTrack->next = NULL;
    return newTrack;
}
/*
void addTrack(Track*& head) {
    Track* newTrack = createTrack();
    
    cout << "Enter track details:" << endl;
    cout << "Title: ";
    cin >> newTrack->title;
    cout << "Artist: ";
    cin >> newTrack->artist;
    cout << "Album: ";
    cin >> newTrack->album;
    cout << "Genre: ";
    cin >> newTrack->genre;
    cout << "Duration: ";
    cin >> newTrack->duration;
    cout << "Release Year: ";
    cin >> newTrack->release_year;
    
    if (head == NULL) {
        head = newTrack;
        head->next = head; 
    } else {
        Track* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newTrack;
        newTrack->next = head; 
    }
    cout << "Track added successfully." << endl;
}
*/
void add_at_head(Track*& head,Track* tail){
    Track* newTrack = createTrack();
    
    cout << "Enter track details:" << endl;
    cout << "Title: ";
    cin >> newTrack->title;
    cout << "Artist: ";
    cin >> newTrack->artist;
    cout << "Album: ";
    cin >> newTrack->album;
    cout << "Genre: ";
    cin >> newTrack->genre;
    cout << "Duration: ";
    cin >> newTrack->duration;
    cout << "Release Year: ";
    cin >> newTrack->release_year;
    newTrack->next=head;
    if (head == NULL) {
        head = newTrack;
        tail=newTrack;
        tail->next=newTrack;   
    }
    else{
        newTrack->next=tail->next;
        tail->next=newTrack;
    }
    cout << "Track added successfully." << endl;
}
void insert_at_end(Track*& head,Track* tail){
    Track* newTrack = createTrack();
    
    cout << "Enter track details:" << endl;
    cout << "Title: ";
    cin >> newTrack->title;
    cout << "Artist: ";
    cin >> newTrack->artist;
    cout << "Album: ";
    cin >> newTrack->album;
    cout << "Genre: ";
    cin >> newTrack->genre;
    cout << "Duration: ";
    cin >> newTrack->duration;
    cout << "Release Year: ";
    cin >> newTrack->release_year;
    newTrack->next=0;
    
    if(head==NULL){
        head=newTrack;
        tail=newTrack;
        tail->next=newTrack;
        cout<<"List is Empty, So Inserted at First Position";
    }
    else{
        newTrack->next=tail->next;
        tail->next=newTrack;
        tail=newTrack;
    }
    cout << "Track added successfully." << endl;
}
void insert_at_spe_pos(Track*& head, Track*& tail) {
    int pos, i = 1;
    cout << "Enter position: ";
    cin >> pos;
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Track* newTrack = createTrack();
    cout << "Enter track details:" << endl;
    cout << "Title: ";
    cin >> newTrack->title;
    cout << "Artist: ";
    cin >> newTrack->artist;
    cout << "Album: ";
    cin >> newTrack->album;
    cout << "Genre: ";
    cin >> newTrack->genre;
    cout << "Duration: ";
    cin >> newTrack->duration;
    cout << "Release Year: ";
    cin >> newTrack->release_year;

    if (pos == 1) {
        if (head == NULL) {
            head = tail = newTrack;
            tail->next = head;
        } else {
            newTrack->next = head;
            head = newTrack;
            tail->next = head; 
        }
    } else {
        Track* temp = head;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }

        if (i == pos - 1) {
            newTrack->next = temp->next;
            temp->next = newTrack;
            if (temp == tail) { 
                tail = newTrack;
            }
        } else {
            cout << "Position exceeds the size of the music library. Inserting at the end." << endl;
            tail->next = newTrack;
            tail = newTrack;
            newTrack->next = head; 
        }
    }
    cout << "Track added successfully." << endl;
}
void delete_at_head(Track*& head, Track*& tail) {
    if (head == NULL) {
        cout << "Music library is empty." << endl;
        return;
    }

    Track* temp = head;
    if (head == tail) { // Only one element
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete temp;
    cout << "Track removed from the head successfully." << endl;
}

void delete_at_end(Track*& head, Track*& tail) {
    if (head == NULL) {
        cout << "Music library is empty." << endl;
        return;
    }

    if (head == tail) { // Only one element
        delete head;
        head = tail = NULL;
    } else {
        Track* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }
    cout << "Track removed from the end successfully." << endl;
}

void delete_at_spe_pos(Track*& head, Track*& tail) {
    if (head == NULL) {
        cout << "Music library is empty." << endl;
        return;
    }
    int pos, i = 1;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Track* temp = head;
    Track* prev = NULL;

    if (pos == 1) {
        if (head == tail) { // Only one element in the list
            head = tail = NULL;
        } else {
            tail->next = head->next;
            head = head->next;
        }
        delete temp;
    } else {
        for (i = 1; temp != NULL && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL || temp == head) {
            cout << "Position exceeds the music library size." << endl;
            return;
        }
        if (temp == tail) {
            tail = prev; 
        }
        prev->next = temp->next;
        delete temp;
    }
    cout << "Track removed successfully." << endl;
}



void displayLibrary(Track* head) {
    if (head == NULL) {
        cout << "Music library is empty." << endl;
    } else {
        Track* temp = head;
        cout << "\n";
        cout << "Title\t\tArtist\t\tAlbum\t\tGenre\t\tDuration\tRelased yr.\n";
        cout<<"-------------------------------------------------------------------------------------------";
        cout<<"\n";
        do {
            cout << temp->title << "\t\t";
            cout << temp->artist << "\t\t";
            cout << temp->album << "\t\t";
            cout << temp->genre << "\t\t";
            cout << temp->duration << "\t\t";
            cout << temp->release_year << endl;
            temp = temp->next;
        } while (temp != head);
    }
}


void searchTrack(Track* head, string title) {
    if (head == NULL) {
        cout << "Music library is empty." << endl;
    } else {
        Track* temp = head;
        bool found = false;
        do {
            if (temp->title == title) {
                cout << "Track found:" << endl;
                cout << "Title: " << temp->title << endl;
                cout << "Artist: " << temp->artist << endl;
                cout << "Album: " << temp->album << endl;
                cout << "Genre: " << temp->genre << endl;
                cout << "Duration: " << temp->duration << endl;
                cout << "Release Year: " << temp->release_year << endl;
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);
        if (!found) {
            cout << "Track not found." << endl;
        }
    }
}


int main() {
    Track* musicLibrary = NULL;
    int choice;
    string title;

    do {
        cout << "\nMusic Library System\n";
        cout << "1. Add Track\n";
        cout << "2. Display All Tracks\n";
        cout << "3. Search Track\n";
        cout << "4. Remove Track\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
//                addTrack(musicLibrary);
                int ch;
                do{
                    cout<<"Insertion at:\n";
                    cout<<"1. Head\n";
                    cout<<"2. End\n";
                    cout<<"3. Speacific Position:\n";
                    cout<<"Enter ur choice: ";
                    cin>>ch;
                    switch(ch){
                        case 1:
                            add_at_head(musicLibrary,musicLibrary);
                        break;
                        case 2:
                            insert_at_end(musicLibrary,musicLibrary);
                        break;
                        case 3:
                            insert_at_spe_pos(musicLibrary,musicLibrary);
                        break;
                    }
                    
                }while(ch==1);
                break;
            case 2:
                displayLibrary(musicLibrary);
                break;
            case 3:
                cout << "Enter track title to search: ";
                cin >> title;
                searchTrack(musicLibrary, title);
                break;
            case 4:
                
                do{
                    cout<<"Deletion at:\n";
                    cout<<"1. Head\n";
                    cout<<"2. End\n";
                    cout<<"3. Speacific Position:\n";
                    cout<<"Enter ur choice: ";
                    cin>>ch;
                    switch(ch){
                        case 1:
                            delete_at_head(musicLibrary,musicLibrary);
                        break;
                        case 2:
                            delete_at_end(musicLibrary,musicLibrary);
                        break;
                        case 3:
                            delete_at_spe_pos(musicLibrary,musicLibrary);
                        break;
                    }
                    
                }while(ch==1);
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
