//Event Registration Management System
#include<stdio.h>
#include<string.h>
//Structure for the Event
struct Event{
    int Eid;
    char event[50];
    char date[50];
    int maxSeats;
};
//Structure for the Participants
struct Participant{
    int Pid;
    char Pname[50];
    char phone[20];
};

struct Organizer{
    int Oid;
    char OName[50];
    char Ophone[20];
};

int getEventLastID();
int getPartLastID();
void AddEvent(); // Function to add event
void DisplayEvent(); // Function to diaplay all the events
void SearchEvent(); // Function to Search a event
void UpdateEvent(); // Function to update an event
void DeleteEvent(); // Function to delete an event
void AddPart(); // Function to add participant
void DisplayPart(); // Function to display all the participants
void SearchPart(); // Function to search for a participant
void UpdatePart(); // Function to update a participant
void DeletePart(); // Function to delete a participant
int getOrgLastID();
void AddOrg();
void DisplayOrg();
void SearchOrg();
void UpdateOrg();
void DeleteOrg();
//Main Function Starts Here
int main(){
    int mainChoice, choice;
    while(1){
    printf("====MENU====\n");
    printf("1. Event Menu\n");
    printf("2. Participants Menu\n");
    printf("3. Organizer\n");
    printf("4. Exit\n");
    scanf("%d", &mainChoice);
    switch(mainChoice){
        case 1:
        while (1)
        {
        printf("====EVENT MENU====\n");
        printf("1. Add an Event\n");
        printf("2. display Event\n");
        printf("3. Search for the Event\n");
        printf("4. Update Event\n");
        printf("5. Delete and Event\n");
        printf("6. Back\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            AddEvent();
            break;
            case 2:
            DisplayEvent();
            break;
            case 3:
            SearchEvent();
            break;
            case 4:
            UpdateEvent();
            break;
            case 5:
            DeleteEvent();
            break;
            case 6:
            break;
            break;
            default:
            printf("!!Please enter valid command!!\n");
            break;
        }
        if (choice == 6) break;
        }
        break;
        case 2:
        while (1){
        printf("====PARTICIPANTS MENU====\n");
        printf("1. Register Participant\n");
        printf("2. Display Participants\n");
        printf("3. Search Participant\n");
        printf("4. Update Participant\n");
        printf("5. Delete Participant\n");
        printf("6. Back\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            AddPart();
            break;
            case 2:
            DisplayPart();
            break;
            case 3:
            SearchPart();
            break;
            case 4:
            UpdatePart();
            break;
            case 5:
            DeletePart();
            break;
            case 6:
            break;
            default:
            printf("!!Please enter valid command!!\n");
            break;
        }
        if (choice == 6) break;
        }
        break;
        case 3:
         while (1){
        printf("====PARTICIPANTS MENU====\n");
        printf("1. Register Organizer\n");
        printf("2. Display Organizer\n");
        printf("3. Search Organizer\n");
        printf("4. Update Organizer\n");
        printf("5. Delete Organizer\n");
        printf("6. Back\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            AddOrg();
            break;
            case 2:
            DisplayOrg();
            break;
            case 3:
            SearchOrg();
            break;
            case 4:
            UpdateOrg();
            break;
            case 5:
            DeleteOrg();
            break;
            case 6:
            break;
            default:
            printf("!!Please enter valid command!!\n");
            break;
        }
        if (choice == 6) break;
        }
        break;
        case 4:
        return 0;
        default:
        printf("!!Invalid Command!!");
        break;
    }
}
}

int getEventLastID(){          // This gives the latest numebr to us for the unique ID
    struct Event e;
    FILE *fp;
    fp = fopen("Event.txt", "r");
    int lastID=0;
    if (fp == NULL){
        printf("!!Cannot fetch the id!!");
        return 1;
    }
    while(fscanf(fp, "%d %s %s %d", &e.Eid, e.event,  e.date, &e.maxSeats)!=EOF){
        lastID = e.Eid;
    }
    fclose(fp);
    return lastID;
}
    //Fuctions for the event starts here
void AddEvent(){             //This function gives helps to create an Event
    struct Event e[100];
    FILE *fp;
    int n;
    fp = fopen("Event.txt", "a");
    if(fp == NULL){
        printf("!!Cannot Find or Create Event File.!!");
        return;
    }
    printf("How many events you want to enter?: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        e[i].Eid = getEventLastID() + i + 1;
        printf("\nEnter event name:");
        scanf("%s", e[i].event);
        printf("Enter date of the event: ");
        scanf("%s", e[i].date);
        printf("Enter the number of maximum seats for event: ");
        scanf("%d", &e[i].maxSeats);
        fprintf(fp, "%d\t%s\t%s\t%d\n", e[i].Eid, e[i].event, e[i].date, e[i].maxSeats);
        printf("Event Stored with ID: %d\n\n", e[i].Eid);
    }
    fclose(fp);
}

void DisplayEvent(){             //This function displays all the data
    struct Event e;
    FILE *fp;
    fp = fopen("Event.txt", "r");
    if(fp == NULL){
        printf("!!Cannot Find The File to Display.!!");
        return;
    }
    printf("EventID\tEvent Name\tEvent Date\tMaxseats\n");
    while(fscanf(fp, "%d %s %s %d", &e.Eid, e.event, e.date, &e.maxSeats)!=EOF){
        printf("%d \t %s \t %s \t %d \n", e.Eid, e.event, e.date, e.maxSeats);
    }
    fclose(fp);
}

void SearchEvent(){                // Searches for a specific Event
    struct Event e;
    int Key, flag=0;
    FILE *fp;
    fp = fopen("Event.txt", "r");
    if(fp == NULL){
        printf("!!Cannot Get The File Data.!!");
        return;
    }
    printf("Enter the ID of the event: ");
    scanf("%d", &Key);
    while(fscanf(fp, "%d %s %s %d", &e.Eid, e.event, e.date, &e.maxSeats)!=EOF){
        if (Key == e.Eid){
            printf("Event Id: %d \t Event Name: %s \t Event Date: %s \t MaxSeats: %d", e.Eid, e.event, e.date, e.maxSeats);
            flag = 1;
        }
        
    }
    if(flag!=1){
        printf("!!The record not found.!!");
    }
    fclose(fp);
}

void UpdateEvent(){                // Updates a specific Event
    struct Event e;
    int key, update = 0;
    FILE *fp, *temp;
    fp = fopen("Event.txt", "r");
    temp = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("Error");
        return;
    }
    printf("Enter an ID to update: ");
    scanf("%d", &key);
    while(fscanf(fp, "%d %s %s %d", &e.Eid, e.event, e.date, &e.maxSeats)!=EOF){
        if(e.Eid == key){
            printf("Enetr Event name: ");
            scanf("%s", e.event);
            printf("Enetr Event Date: ");
            scanf("%s", e.date);
            printf("Enetr maxSeats: ");
            scanf("%d", &e.maxSeats);
            update = 1;
        }
        fprintf(temp, "%d\t%s\t%s\t%d\n", e.Eid, e.event, e.date, e.maxSeats);
    }
    fclose(fp);
    fclose(temp);
    remove("Event.txt");
    rename("temp.txt", "Event.txt");
    if(update){
        printf("!!Event Updated successfully!!");
    }
    else{
        printf("!!Update Failed!!");
    }
}

void DeleteEvent(){               //Deletes an specific Event
    struct Event e;
    int key, deleted = 0;
    FILE *fp, *temp;
    fp = fopen("Event.txt", "r");
    temp = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("Error");
        return;
    }
    printf("Enter an ID the delete the Event: ");
    scanf("%d", &key);
    while(fscanf(fp, "%d %s %s %d", &e.Eid, e.event, e.date, &e.maxSeats)!=EOF){
        if(e.Eid != key){
            fprintf(temp, "%d %s %s %d\n", e.Eid, e.event, e.date, e.maxSeats);
        }
        else{
            deleted = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("Event.txt");
    rename("temp.txt", "Event.txt");
    if(deleted){
        printf("!!Deleted Successfully!!");
    }
    else{
        printf("!!Cannot Delete the Event!!");
    }
}
      //Functions for the Participant.txt starts here
int getPartLastID(){           // This gives the latest numebr to us for the unique ID
    struct Participant p;
    FILE *fp;
    fp = fopen("Participant.txt", "r");
    int lastID=0;
    if (fp == NULL){
        printf("!!Cannot fetch the id!!");
        return 1;
    }
    while(fscanf(fp, "%d %s %s", &p.Pid, p.Pname, p.phone)!=EOF){
        lastID = p.Pid;
    }
    fclose(fp);
    return lastID;
}

void AddPart(){             //This function gives helps to create an Event
    struct Participant p[100];
    FILE *fp;
    int n;
    int lastID = getPartLastID();
    fp = fopen("Participant.txt", "a");
    if(fp == NULL){
        printf("!!Cannot Find or Create Event File.!!");
        return;
    }
    printf("How many events you want to enter?: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        p[i].Pid = lastID+i+1;
        printf("\nEnter Participant's name:");
        scanf("%s", p[i].Pname);
        printf("Enter Phone no. of Participant: ");
        scanf("%s", p[i].phone);
        fprintf(fp, "%d\t%s\t%s\n", p[i].Pid, p[i].Pname, p[i].phone);
        printf("Event Stored with ID: %d\n\n", p[i].Pid);
    }
    fclose(fp);
}

void DisplayPart(){             //This function displays all the data
    struct Participant p;
    int i=0;
    FILE *fp;
    fp = fopen("Participant.txt", "r");
    if(fp == NULL){
        printf("!!Cannot Find The File to Display.!!");
        return;
    }
    printf("ParticipantID\tParticipant Name\tPhone no.\n");
    while(fscanf(fp, "%d %s %s", &p.Pid, p.Pname, p.phone)!=EOF){
        printf("%d \t %s \t %s \n", p.Pid, p.Pname, p.phone);
    }
    fclose(fp);
}

void SearchPart(){                // Searches for a specific Event
    struct Participant p;
    int Key, flag=0;
    FILE *fp;
    fp = fopen("Participant.txt", "r");
    if(fp == NULL){
        printf("!!Cannot Get The File Data.!!");
        return;
    }
    printf("Enter the ID of the Participant: ");
    scanf("%d", &Key);
    while(fscanf(fp, "%d %s %s", &p.Pid, p.Pname, p.phone)!=EOF){
        if (Key == p.Pid){
            printf("Participant Id: %d \t Participant Name: %s \t Participant Phone no.: %s", p.Pid, p.Pname, p.phone);
            flag = 1;
        }
        
    }
    if(flag!=1){
        printf("!!The record not found.!!");
    }
    fclose(fp);
}

void UpdatePart(){                // Updates a specific Event
    struct Participant p;
    int key, update = 0;
    FILE *fp, *temp;
    fp = fopen("Participant.txt", "r");
    temp = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("Error");
        return;
    }
    printf("Enter an ID to update: ");
    scanf("%d", &key);
    while(fscanf(fp, "%d %s %s", &p.Pid, p.Pname, p.phone)!=EOF){
        if(p.Pid == key){
            printf("Enetr Participant name: ");
            scanf("%s", p.Pname);
            printf("Enetr Participant Phone no.: ");
            scanf("%s", p.phone);
            update = 1;
        }
        fprintf(temp, "%d\t%s\t%s\n", p.Pid, p.Pname, p.phone);
    }
    fclose(fp);
    fclose(temp);
    remove("Participant.txt");
    rename("temp.txt", "Participant.txt");
    if(update){
        printf("!!Event Updated successfully!!");
    }
    else{
        printf("!!Update Failed!!");
    }
}

void DeletePart(){               //Deletes an specific Event
    struct Participant p;
    int key, deleted = 0;
    FILE *fp, *temp;
    fp = fopen("Participant.txt", "r");
    temp = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("Error");
        return;
    }
    printf("Enter an ID the delete the Participant: ");
    scanf("%d", &key);
    while(fscanf(fp, "%d %s %s", &p.Pid, p.Pname, p.phone)!=EOF){
        if(p.Pid != key){
            fprintf(temp, "%d %s %s\n", p.Pid, p.Pname, p.phone);
        }
        else{
            deleted = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("Participant.txt");
    rename("temp.txt", "Participant.txt");
    if(deleted){
        printf("!!Deleted Successfully!!");
    }
    else{
        printf("!!Cannot Delete the Event!!");
    }
}

int getOrgLastID(){
    struct Organizer o;
    FILE *fp;
    fp = fopen("Organizer.txt", "r");
    int LastID=0;
    if(fp==NULL){
        printf("!!cannot Fetch Organizers.!!");
        return 1;
    }
    while(fscanf(fp, "%d %s, %s", &o.Oid, o.OName, o.Ophone)!=EOF){
        LastID = o.Oid;
    }
    fclose(fp);
    return LastID;
}

void addOrg(){
    struct Organizer o[100];
    int n;
    FILE *fp;
    fp = fopen("Organizer.txt", "w");
    if(fp==NULL){
        printf("!!cannot add data!!");
        return;
    }
    printf("How may organizers You want to add: ");
    scanf("%d", &n);
    for (int i=0; i<n;i++){
        o[i].Oid = getOrgLastID() + i + 1;
        printf("\nEnter Organizer's name: ");
        scanf("%s", o[i].OName);
        printf("\nEnter the Contact of Organizer: ");
        scanf("%s", o[i].Ophone);
        fprintf(fp, "%d\t%s\t%s", o[i].Oid, o[i].OName, o[i].Ophone);
        printf("\nEvent Stored with ID: %d\n", o[i].Oid);
    }
    fclose(fp);
}

void DisplayOrg(){
    struct Organizer o;
    FILE *fp;
    fp = fopen("Organizer.txt", "r");
    if(fp == NULL){
        printf("!!Cannot Open The File!!");
        return;
    }
    printf("organizerID\tOrganizer Name\tContact");
    while(fscanf(fp, "%d %s %s", &o.Oid, o.OName, o.Ophone)!=EOF){
        printf("%d \t %s \t %s\n", o.Oid, o.OName, o.Ophone);
    }
    fclose(fp);
}

void SearchOrg(){
    struct Organizer o;
    int key, flag=0;
    FILE *fp;
    fp = fopen("Organizer.txt", "r");
    if (fp==NULL){
        printf("!!Cannot Open The File!!");
        return;
    }
    printf("Enter the ID of the Organizer: ");
    scanf("%d", &key);
    while(fscanf(fp,"%d %s %S", &o.Oid, o.OName, o.Ophone)!=EOF){
        if (key == o.Oid){
            printf("Organizer ID: %d \t Name: %s \t Contact: %s", o.Oid, o.OName, o.Ophone);
            flag = 1;
        }
    }
    if(flag!=1){
        printf("!!The Record Not Found!!");
    }
    fclose(fp);
}

void UpdateOrg(){
    struct Organizer o;
    FILE *fp, *temp;
    int Key, update = 0;
    fp = fopen("Organizer.txt", "r");
    temp = fopen("temp.txt", "w");
    if (fp == NULL){
        printf("!!Cannot Open The File!!");
        return;
    }
    printf("Enter an ID to Update: ");
    scanf("%d", &Key);
    while(fscanf(fp, "%d %s %s", &o.Oid, o.OName, o.Ophone)!=EOF){
        if(o.Oid == Key){
            printf("Enter Organizer Name: ");
            scanf("%s", o.OName);
            printf("Enter Organizer Contact: ");
            scanf("%s", o.Ophone);
            update = 1;
        }
        fprintf(temp, "%d\t%s\t%s", o.Oid, o.OName, o.Ophone);
    }
    fclose(fp);
    fclose(temp);
    remove("Organizer.txt");
    rename("temp.txt", "Organizer.txt");
    if(update){
        printf("!!Organizer Updated Successfully!!");
    }
    else{
        printf("!!Update Failed!!");
    }
}

void DeleteOrg(){
    struct Organizer o;
    int Key, deleted = 0;
    FILE *fp, *temp;
    fp = fopen("Organizer.txt", "r");
    temp = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("!!Cannot Open File!!");
        return;
    }
    printf("enter an ID to delete an Organizer: ");
    scanf("%d", &Key);
    while(fscanf(fp, "%d %s %s", &o.Oid, o.OName, o.Ophone)!=EOF){
        if(o.Oid == Key){
            printf()
        }
    }
}