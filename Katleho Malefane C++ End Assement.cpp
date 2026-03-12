#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

// Function to validate phone numbers
bool isValidPhoneNumber(const string & phone) 
{
    return phone.length() == 8 && all_of(phone.begin(), phone.end(), ::isdigit);
}

// Function to validate if a string contains only digits
bool isDigits(const string & str) 
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

// Function to validate the date length
bool isValidDate(const string & date) 
{
    return date.length() == 10; 
}

// Class User
class User {
public:
    string firstname;
    string surname;
    string dob;

    virtual void getFullName() {
        cout << "Enter firstname: ";
        getline(cin, firstname);
        cout << "Enter surname: ";
        getline(cin, surname);
    }
};

// Class Child
class Child : public User {
public:
    string middlename;
    string mother;
    string father;
    string village;
    string chief;
    string district;
    string recordID;

    void getFullName() override {
        cout << "\n--- Child Registration Form ---\n";
        User::getFullName();
        cout << "Enter middlename: ";
        getline(cin, middlename);
        
        do {
            cout << "Enter date of birth (dd-mm-yyyy): ";
            getline(cin, dob);
            if (!isValidDate(dob)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(dob));

        cout << "Enter mother's name: ";
        getline(cin, mother);
        cout << "Enter father's name: ";
        getline(cin, father);
        cout << "Enter village: ";
        getline(cin, village);
        cout << "Enter chief: ";
        getline(cin, chief);
        cout << "Enter district: ";
        getline(cin, district);
    }

    void generateChildRecordID(int recordNumber) {
        string firstPart = firstname.substr(0, 3);
        string secondPart = surname.substr(0, 3);
        string datePart = dob.substr(0, 2) + dob.substr(3, 2) + dob.substr(6, 4);
        string recordNum = to_string(recordNumber);

        for (char& c : firstPart) c = toupper(c);
        for (char& c : secondPart) c = toupper(c);
        for (char& c : datePart) c = toupper(c);

        recordID = firstPart + "-" + secondPart + "-" + datePart + "-" + recordNum;
    }

    string getRecordID() const {
        return recordID;
    }

    void DisplayChildInfo() const {
        cout << "##########################################" << endl;
        cout << "#       Child Registration Form          #" << endl;
        cout << "##########################################" << endl;
        cout << "# Child Firstname: " << firstname << endl;
        cout << "# Child Surname: " << surname << endl;
        cout << "# Child Middlename: " << middlename << endl;
        cout << "# Date of birth: " << dob << endl;
        cout << "# Mother's Name: " << mother << endl;
        cout << "# Father's Name: " << father << endl;
        cout << "# Village: " << village << endl;
        cout << "# Chief: " << chief << endl;
        cout << "# District: " << district << endl;
        cout << "# Record ID: " << recordID << endl;
        cout << "##########################################" << endl;
    }
};

// Class Doctor
class Doctor : public User {
public:
    string Resident;
    string hospital_Address;
    string cellphone;
    string practice_number;

    void RegisterDoctor() {
        cout << "\n--- Doctor Registration Form ---\n";
        User::getFullName();
        cout << "Enter practice number: ";
        getline(cin, practice_number);
        cout << "Enter Residence (Hospital/Clinic): ";
        getline(cin, Resident);
        cout << "Enter Hospital Address: ";
        getline(cin, hospital_Address);
        do {
            cout << "Enter doctor cellphone (8 digits): ";
            getline(cin, cellphone);
            if (!isValidPhoneNumber(cellphone)) {
                cout << "Invalid cellphone number. It should be exactly 8 digits long.\n";
            }
        } while (!isValidPhoneNumber(cellphone));
    }

    void DisplayDoctorInfo() const {
        cout << "##########################################" << endl;
        cout << "#       Doctor Registration Form         #" << endl;
        cout << "##########################################" << endl;
        cout << "# Doctor Firstname: " << firstname << endl;
        cout << "# Doctor Surname: " << surname << endl;
        cout << "# Doctor Practice number: " << practice_number << endl;
        cout << "# Resident Hospital/Clinic: " << Resident << endl;
        cout << "# Hospital Address: " << hospital_Address << endl;
        cout << "# Doctor Cell phone number: " << cellphone << endl;
        cout << "##########################################" << endl;
    }
};

// Nurse Class
class Nurse : public User 
{
public:
    string title;
    string clinic;
    string clinic_Address;
    string practice_number;
    string cellphone;

    void RegisterNurse() {
        cout << "\n--- Nurse Registration Form ---\n";
        cout << "Enter Title: ";
        getline(cin, title);
        User::getFullName();
        cout << "Enter practice number: ";
        getline(cin, practice_number);
        cout << "Enter clinic: ";
        getline(cin, clinic);
        cout << "Enter Clinic Address: ";
        getline(cin, clinic_Address);
        do {
            cout << "Enter cellphone (8 digits): ";
            getline(cin, cellphone);
            if (!isValidPhoneNumber(cellphone)) {
                cout << "Invalid cellphone number. It should be exactly 8 digits long.\n";
            }
        } while (!isValidPhoneNumber(cellphone));
    }

    void DisplayNurseInfo() const 
    {
        cout << "#######################################" << endl;
        cout << "#       Nurse Registration Form       #" << endl;
        cout << "#######################################" << endl;
        cout << "# Nurse Title: " << title << endl;
        cout << "# Nurse Firstname: " << firstname << endl;
        cout << "# Nurse Surname: " << surname << endl;
        cout << "# Nurse Practice number: " << practice_number << endl;
        cout << "# Resident Hospital/Clinic: " << clinic << endl;
        cout << "# Hospital Address: " << clinic_Address << endl;
        cout << "# Nurse Cell phone number: " << cellphone << endl;
        cout << "########################################" << endl;
    }
};

// Base class for medical and vaccination records
class Treatment_Record {
public:
    string treatment;
    string child_record;
    double weight;  
    double height;  
    string clinic;

    virtual void Records() {
        cout << "Enter treatment: ";
        getline(cin, treatment);
        cout << "Enter child record: ";
        getline(cin, child_record);

        // Validate weight input
        do {
            cout << "Enter weight (numeric): ";
            cin >> weight; 
            if (cin.fail()) {
                cout << "Invalid input. Weight must be numeric.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail());

        // Validate height input
        do {
            cout << "Enter height (numeric): ";
            cin >> height; // Read directly into double
            if (cin.fail()) {
                cout << "Invalid input. Height must be numeric.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail());

        cin.ignore(); 
        cout << "Enter clinic: ";
        getline(cin, clinic);
    }
};

// Class Vaccination Record
class Vaccination : public Treatment_Record 
{
public:
    string vaccine;
    string nurse;
    string clinic_Date;
    string Next_Clinic_Date;

    void Capture_Vaccination_Record() {
        cout << "\n--- Capture Vaccination Record ---\n";
        Treatment_Record::Records();
        cout << "Enter Vaccine: ";
        getline(cin, vaccine);
        cout << "Enter Nurse Name: ";
        getline(cin, nurse);
        
        do {
            cout << "Enter Clinic Date (dd-mm-yyyy): ";
            getline(cin, clinic_Date);
            if (!isValidDate(clinic_Date)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(clinic_Date));

        do {
            cout << "Enter Next Clinic Date (dd-mm-yyyy): ";
            getline(cin, Next_Clinic_Date);
            if (!isValidDate(Next_Clinic_Date)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(Next_Clinic_Date));
    }

    void Display_Vaccination_Records() const {
        cout << "#########################################" << endl;
        cout << "#   --------Vaccination Record------    #" << endl;
        cout << "#########################################" << endl;
        cout << "# Treatment: " << treatment << endl;
        cout << "# Child Record ID: " << child_record << endl;
        cout << fixed << setprecision(2);  // Show 2 decimal points
        cout << "# Weight: " << weight << " kg" << endl;
        cout << "# Height: " << height << " cm" << endl;
        cout << "# Clinic: " << clinic << endl;
        cout << "# Vaccine: " << vaccine << endl;
        cout << "# Nurse Name: " << nurse << endl;
        cout << "# Clinic Date: " << clinic_Date << endl;
        cout << "# Next Clinic Date: " << Next_Clinic_Date << endl;
        cout << "###########################################" << endl;
    }

    void SaveVaccinationRecord() const {
        string filename = child_record + "_vaccination_record.txt";
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            file << "Vaccination Record:" << endl;
            file << "===================" << endl;
            file << "Treatment: " << treatment << endl;
            file << "Child Record ID: " << child_record << endl;
            file << fixed << setprecision(2);  // Show 2 decimal points
            file << "Weight: " << weight << " kg" << endl;
            file << "Height: " << height << " cm" << endl;
            file << "Clinic: " << clinic << endl;
            file << "Vaccine: " << vaccine << endl;
            file << "Nurse Name: " << nurse << endl;
            file << "Clinic Date: " << clinic_Date << endl;
            file << "Next Clinic Date: " << Next_Clinic_Date << endl;
            file.close();
            cout << "Vaccination record saved to " << filename << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void UpdateVaccinationRecord(const string& newTreatment, const string& newVaccine) {
        treatment = newTreatment;
        vaccine = newVaccine;
        cout << "Vaccination record updated." << endl;
    }
};

// Class Medical Records
class Medical : public Treatment_Record {
public:
    string medication;
    string doctor;
    string consultation_Date;
    string checkup_Date;

    void Capture_Medical_Record() {
        cout << "\n--- Capture Medical Record ---\n";
        Treatment_Record::Records();
        cout << "Enter Medication given: ";
        getline(cin, medication);
        cout << "Enter Doctor's name: ";
        getline(cin, doctor);
        
        do {
            cout << "Enter Consultation Date (dd-mm-yyyy): ";
            getline(cin, consultation_Date);
            if (!isValidDate(consultation_Date)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(consultation_Date));

        do {
            cout << "Enter Checkup Date (dd-mm-yyyy): ";
            getline(cin, checkup_Date);
            if (!isValidDate(checkup_Date)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(checkup_Date));
    }
    
    void DisplayMedicalRecords() const {
        cout << "#########################################" << endl;
        cout << "#  ---------Medical Record----------    #" << endl;
        cout << "#########################################" << endl;
        cout << "# Treatment: " << treatment << endl;
        cout << "# Child Record ID: " << child_record << endl;
        cout << fixed << setprecision(2); // Show 2 decimal points
        cout << "# Weight: " << weight << " kg" << endl;
        cout << "# Height: " << height << " cm" << endl;
        cout << "# Clinic: " << clinic << endl;
        cout << "# Medication: " << medication << endl;
        cout << "# Doctor's Name: " << doctor << endl;
        cout << "# Consultation Date: " << consultation_Date << endl;
        cout << "# Checkup Date: " << checkup_Date << endl;
        cout << "###########################################" << endl;
    }

    void SaveMedicalRecord() const {
        string filename = child_record + "_medical_record.txt";
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            file << "Medical Record:" << endl;
            file << "===================" << endl;
            file << "Treatment: " << treatment << endl;
            file << "Child Record ID: " << child_record << endl;
            file << fixed << setprecision(2); // Show 2 decimal points
            file << "Weight: " << weight << " kg" << endl;
            file << "Height: " << height << " cm" << endl;
            file << "Clinic: " << clinic << endl;
            file << "Medication: " << medication << endl;
            file << "Doctor's Name: " << doctor << endl;
            file << "Consultation Date: " << consultation_Date << endl;
            file << "Checkup Date: " << checkup_Date << endl;
            file.close();
            cout << "Medical record saved to " << filename << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void UpdateMedicalRecord(const string& newTreatment, const string& newMedication) {
        treatment = newTreatment;
        medication = newMedication;
        cout << "Medical record updated." << endl;
    }
};

// Base Class for generating reports
class Genarate_Report {
public:
    string Child_Fullname;
    string parent; 
    string Date_of_birth;
    string Place_of_birth; 
    double weight; 
    double height; 
    string Date;

    virtual void Capture_Report() {
        cout << "Enter Child fullname: ";
        getline(cin, Child_Fullname);
        cout << "Enter Guardian's name (Mother's name): ";
        getline(cin, parent); 
        
        // Validate date of birth input
        do {
            cout << "Enter Child Date of birth (dd-mm-yyyy): ";
            getline(cin, Date_of_birth);
            if (!isValidDate(Date_of_birth)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(Date_of_birth));

        cout << "Enter Place of Birth (Village): ";
        getline(cin, Place_of_birth); 
        
        // Validate weight input
        do {
            cout << "Enter weight (numeric): ";
            cin >> weight; 
            if (cin.fail()) {
                cout << "Invalid input. Weight must be numeric.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail());

        // Validate height input
        do {
            cout << "Enter Height (numeric): ";
            cin >> height; 
            if (cin.fail()) {
                cout << "Invalid input. Height must be numeric.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail());

        cin.ignore(); 
        cout << "Enter Clinic Date (dd-mm-yyyy): ";
        
        do {
            getline(cin, Date);
            if (!isValidDate(Date)) {
                cout << "Invalid date format! Please enter a date of length 10." << endl;
            }
        } while (!isValidDate(Date));
    }
};

// Class Vaccination Report
class Vaccination_Report : public Genarate_Report {
public:
    string vaccine;
    string nurse_name;
    string clinic_name;

    // Add a constructor
    Vaccination_Report() {}

    Vaccination_Report(const Vaccination& vaccinationRecord, const string& motherName, const string& village, const string& district,const string& dob) 
    {
        Child_Fullname = vaccinationRecord.child_record; 
        Date_of_birth = dob;  
        parent = motherName;  
        Place_of_birth = village + ", " + district; 
        weight = vaccinationRecord.weight;
        height = vaccinationRecord.height;
        vaccine = vaccinationRecord.vaccine;
        nurse_name = vaccinationRecord.nurse;
        clinic_name = vaccinationRecord.clinic;
        Date = vaccinationRecord.clinic_Date; 
    }

    void Display_Generated_Report() const {
        cout << "#######################################################################" << endl;
        cout << "#            Child's Vaccination Generated Report                    #" << endl;
        cout << "# #####################################################################" << endl;
        cout << "# Child Fullname: " << maskChildFullname(Child_Fullname) << endl;
        cout << "# Date of Birth: " << maskDate(Date_of_birth) << endl;
        cout << "# Guardian/Parents' Name(s): " << maskGuardianName(parent) << endl;
        cout << "# Place of Birth: " << Place_of_birth << endl;
        cout << fixed << setprecision(2);  // Show 2 decimal points
        cout << "# Vaccinations Administered:" << endl;
        cout << "# -> Vaccine: " << maskVaccine() << " | Weight: " << weight << " kg | Height: " << height << " cm | Date: " << Date << " | By: " << nurse_name << " | Clinic: " << clinic_name << endl;
        cout << "#########################################################################" << endl;
    }

    void printReport(const string& recordID) const {
        string filename = recordID + ".txt"; 
        ofstream file(filename);
        if (file.is_open()) {
            file << "#########################################################################" << endl;
            file << "#        Child's Vaccination Generated Report                           #" << endl;
            file << "#########################################################################" << endl;
            file << "# Child Fullname: " << maskChildFullname(Child_Fullname) << endl;
            file << "# Date of Birth: " << maskDate(Date_of_birth) << endl;
            file << "# Guardian/Parents' Name(s): " << maskGuardianName(parent) << endl;
            file << "# Place of Birth: " << Place_of_birth << endl;
            file << fixed << setprecision(2);  
            file << "# Vaccinations Administered:" << endl;
            file << "# -> Vaccine: " << maskVaccine() << " | Weight: " << weight << " kg | Height: " << height << " cm | Date: " << Date << " | By: " << nurse_name << " | Clinic: " << clinic_name << endl;
            file << "##########################################################################" << endl;
            file.close();
            cout << "Vaccination report printed to " << filename << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    string maskChildFullname(const string& fullname) const
    { 
        stringstream ss(fullname);
        string first_name, middle_name, last_name;
        ss >> first_name >> middle_name >> last_name;

        // Mask the first name
        string masked_first;
        if (first_name.length() <= 1) {
            masked_first = string(first_name.length(), '*'); 
        } else {
            masked_first = first_name[0] + string(first_name.length() - 1, '*'); 
        }

        // Mask the middle name completely
        string masked_middle = string(middle_name.length(), '*');

        // Mask the last name and leave the last 3 letters 
        string masked_last;
        if (last_name.length() <= 3) {
            masked_last = last_name; 
        } else {
            masked_last = string(last_name.length() - 3, '*') + last_name.substr(last_name.length() - 3);
        }

        // Combine the masked names
        return masked_first + " " + masked_middle + " " + masked_last;
    }

    string maskGuardianName(const string &name) const 
    {
        stringstream ss(name);
        string first_name, surname;

        ss >> first_name; 
        ss >> surname;    

        string masked_first = maskSingleName(first_name);
        string masked_surname = maskSingleName(surname);

        return masked_first + " " + masked_surname;
    }

    string maskSingleName(const string &name) const 
    {
        if (name.length() <= 1) {
            return name; 
        }
        return name[0] + string(name.length() - 1, '*'); 
    }

    string maskDate(const string &date) const 
    {
        if (date.length() == 10) {
            return "**/**/" + date.substr(6, 4);
        }
        return date;
    }

    string maskVaccine() const 
    {
        return string(vaccine.length(), '*');
    }
};

// Class Medical Report
class Medical_Report : public Genarate_Report 
{
public:
    string Medication;
    string Doctor_name;
    string Hospital_name;

    // Add a default constructor
    Medical_Report() {}
    
    // Existing constructor to create report from existing record
    Medical_Report(const Medical& medicalRecord, const string& motherName, const string& village, const string& district, const string& dob) 
    {
        Child_Fullname = medicalRecord.child_record;
        Date_of_birth = dob;  
        parent = motherName;
        Place_of_birth = village + ", " + district; 
        weight = medicalRecord.weight;
        height = medicalRecord.height;
        Medication = medicalRecord.medication;
        Doctor_name = medicalRecord.doctor;
        Hospital_name = medicalRecord.clinic; 
        Date = medicalRecord.consultation_Date; 
    }

    void Display_Generated_Report() const 
    {
        cout << "##########################################################################" << endl; 
        cout << "#           Child's Medical Generated Report                             #" << endl;
        cout << "##########################################################################" << endl;
        cout << "# Child Fullname: " << maskChildFullname(Child_Fullname) << endl;
        cout << "# Date of Birth: " << maskDate(Date_of_birth) << endl;
        cout << "# Guardian/Parents' Name(s): " << maskGuardianName(parent) << endl;
        cout << "# Place of Birth: " << Place_of_birth << endl;
        cout << fixed << setprecision(2); 
        cout << "# Medical Consultation:" << endl;
        cout << "# -> Medication: " << maskMedical() << " | Weight: " << weight << " kg | Height: " << height << " cm | Date: " << Date << " | By: " << Doctor_name << " | Clinic: " << Hospital_name << endl;
        cout << "##########################################################################" << endl;
    }

    void printReport(const string& recordID) const 
    {
        string filename = recordID + ".txt"; 
        ofstream file(filename);
        if (file.is_open()) {
            file << "#######################################################################" << endl;
            file << "#                Child's Medical Generated Report                     #" << endl;
            file << "#######################################################################" << endl;
            file << "# Child Fullname: " << maskChildFullname(Child_Fullname) << endl;
            file << "# Date of Birth: " << maskDate(Date_of_birth) << endl;
            file << "# Guardian/Parents' Name(s): " << maskGuardianName(parent) << endl;
            file << "# Place of Birth: " << Place_of_birth << endl;
            file << fixed << setprecision(2); 
            file << "# Medical Consultation:" << endl;
            file << "# -> Medication: " << maskMedical() << " | Weight: " << weight << " kg | Height: " << height << " cm | Date: " << Date << " | By: " << Doctor_name << " | Clinic: " << Hospital_name << endl;
            file << "#######################################################################" << endl;
            file.close();
            cout << "Report printed to " << filename << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

private:
    string maskChildFullname(const string& fullname) const 
    { 
        stringstream ss(fullname);
        string first_name, middle_name, last_name;

        // Extract first, middle, and last names from the input
        ss >> first_name >> middle_name >> last_name;

        // Mask the first name
        string masked_first;
        if (first_name.length() <= 1) {
            masked_first = string(first_name.length(), '*'); 
        } else {
            masked_first = first_name[0] + string(first_name.length() - 1, '*');
        }

        // Mask the middle name completely
        string masked_middle = string(middle_name.length(), '*');

        // Mask the last name and leave the last 3 letters
        string masked_last;
        if (last_name.length() <= 3) {
            masked_last = last_name;
        } else {
            masked_last = string(last_name.length() - 3, '*') + last_name.substr(last_name.length() - 3);
        }

        // Combine the masked names
        return masked_first + " " + masked_middle + " " + masked_last;
    }

    string maskGuardianName(const string &name) const 
    {
        stringstream ss(name);
        string first_name, surname;

        ss >> first_name; 
        ss >> surname;    

        string masked_first = maskSingleName(first_name);
        string masked_surname = maskSingleName(surname);

        return masked_first + " " + masked_surname;
    }

    string maskSingleName(const string &name) const {
        if (name.length() <= 1) {
            return name; 
        }
        return name[0] + string(name.length() - 1, '*'); 
    }

    string maskDate(const string &date) const 
    {
    if (date.length() == 10) {
        return "**/**/" + date.substr(6, 2) + "**"; // Adjusted to get the last two digits of the year
    }
    return date;
   }

    string maskMedical() const {
        return string(Medication.length(), '*');
    }
};

// Function for Updating Vaccination Records
void UpdateVaccinationRecord(vector<Vaccination>& vaccinationRecords, const string& recordID) 
{
    for (auto& record : vaccinationRecords) {
        if (record.child_record == recordID) {
            cout << "Updating record for Child Record ID: " << recordID << endl;
            string newTreatment, newVaccine;
            cout << "Enter new details for treatment: ";
            getline(cin, newTreatment);
            cout << "Enter new Vaccine: ";
            getline(cin, newVaccine);
            record.UpdateVaccinationRecord(newTreatment, newVaccine);
            
            record.Display_Vaccination_Records(); 
            return;
        }
    }
    cout << "No vaccination record found for Record ID: " << recordID << endl;
}

// Function for Deleting Vaccination Records
void DeleteVaccinationRecord(vector<Vaccination>& vaccinationRecords, const string& recordID) 
{
    auto it = remove_if(vaccinationRecords.begin(), vaccinationRecords.end(),
                        [&](Vaccination &record) { return record.child_record == recordID; });
    if (it != vaccinationRecords.end()) {
        vaccinationRecords.erase(it, vaccinationRecords.end());
        cout << "Vaccination record for Record ID: " << recordID << " has been deleted." << endl;
        
        cout << "\nRemaining Vaccination Records:\n";
        for (const auto& record : vaccinationRecords) {
            record.Display_Vaccination_Records(); 
        }
    } else {
        cout << "No vaccination record found for Record ID: " << recordID << endl;
    }
}

// Function for Updating Medical Records
void UpdateMedicalRecord(vector<Medical>& medicalRecords, const string& recordID) 
{
    for (auto& record : medicalRecords) {
        if (record.child_record == recordID) {
            cout << "Updating record for Child Record ID: " << recordID << endl;
            string newTreatment, newMedication;
            cout << "Enter new details for treatment: ";
            getline(cin, newTreatment);
            cout << "Enter new Medication: ";
            getline(cin, newMedication);
            record.UpdateMedicalRecord(newTreatment, newMedication);
            
            record.DisplayMedicalRecords(); 
            return;
        }
    }
    cout << "No medical record found for Record ID: " << recordID << endl;
}

// Function for Deleting Medical Record
void DeleteMedicalRecord(vector<Medical>& medicalRecords, const string& recordID) 
{
    auto it = remove_if(medicalRecords.begin(), medicalRecords.end(),
                        [&](Medical &record) { return record.child_record == recordID; });
    if (it != medicalRecords.end()) {
        medicalRecords.erase(it, medicalRecords.end());
        cout << "Medical record for Record ID: " << recordID << " has been deleted." << endl;
        
        cout << "\nRemaining Medical Records:\n";
        for (const auto& record : medicalRecords) {
            record.DisplayMedicalRecords(); 
        }
    } else {
        cout << "No medical record found for Record ID: " << recordID << endl;
    }
}

// Function for searching medical records
void searchMedicalRecords(const vector<Medical>& medicalRecords, const string& recordID) 
{
    bool found = false;
    for (const auto& record : medicalRecords) {
        if (record.child_record == recordID) {
            record.DisplayMedicalRecords();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No medical record found for Record ID: " << recordID << endl;
    }
}

// Function to search vaccination records
void searchVaccinationRecords(const vector<Vaccination>& vaccinationRecords, const string& recordID) 
{
    bool found = false;
    for (const auto& record : vaccinationRecords) {
        if (record.child_record == recordID) {
            record.Display_Vaccination_Records();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No vaccination record found for Record ID: " << recordID << endl;
    }
}

// Function to search by name and DOB
void searchByNameAndDOB(const vector<Child>& children, const vector<Medical>& medicalRecords,
    const vector<Vaccination>& vaccinationRecords, const string& name,
    const string& surname, const string& dob) 
{
    bool found = false;

    for (const auto& child : children) {
        if (child.firstname == name && child.surname == surname && child.dob == dob) {
            cout << "Found Child: " << child.firstname << " " << child.surname
                << " with Record ID: " << child.getRecordID() << endl;

            searchMedicalRecords(medicalRecords, child.getRecordID());
            searchVaccinationRecords(vaccinationRecords, child.getRecordID());

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Child not found with the provided information!" << endl;
    }
}

int main() {
    vector<Child> children;
    vector<Nurse> nurses;
    vector<Doctor> doctors;
    vector<Vaccination> vaccinationRecords;
    vector<Medical> medicalRecords;

    while (true) {
        cout << "######################################" << endl;
        cout << "#            Main Menu               #" << endl;
        cout << "######################################" << endl;
        cout << "# 1. Register                        #" << endl;
        cout << "# 2. Login                           #" << endl;
        cout << "# 3. Search Child Information        #" << endl;
        cout << "######################################" << endl;
        cout << "Select an option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        // Registration 
        if (choice == 1) {
            cout << "Register as:\n1. Child\n2. Nurse\n3. Doctor\n";
            cout << "Enter your choice: ";
            int regChoice;
            cin >> regChoice;
            cin.ignore();

            if (regChoice == 1) {
                Child newChild;
                newChild.getFullName();
                newChild.generateChildRecordID(children.size() + 1);
                cout << "Child registered successfully! Generated Record ID: " << newChild.getRecordID() << endl;
                children.push_back(newChild);
                newChild.DisplayChildInfo();
            } else if (regChoice == 2) {
                Nurse newNurse;
                newNurse.RegisterNurse();
                nurses.push_back(newNurse);
                cout << "Nurse registered successfully!" << endl;
                newNurse.DisplayNurseInfo();
            } else if (regChoice == 3) {
                Doctor newDoctor;
                newDoctor.RegisterDoctor();
                doctors.push_back(newDoctor);
                cout << "Doctor registered successfully!" << endl;
                newDoctor.DisplayDoctorInfo();
            } else {
                cout << "Invalid registration option!" << endl;
            }
         // Login part
        } else if (choice == 2) {
            cout << "Login as:\n1. Child\n2. Nurse\n3. Doctor\n";
            cout << "Enter your choice: ";
            int loginChoice;
            cin >> loginChoice;
            cin.ignore();

            if (loginChoice == 1) {
                string username, password;
                cout << "Enter Username (Full Name): ";
                getline(cin, username);
                cout << "Enter Password (Child Record ID): ";
                getline(cin, password);

                for (auto& child : children) {
                    if (child.firstname + " " + child.surname == username) 
                    {
                        if (password == child.getRecordID()) {
                            cout << "Login successful as Child!" << endl;

                            // Display reports based on existing records
                            Vaccination_Report vaccination_report{};
                            Medical_Report medical_report{};

                            for (const auto& record : vaccinationRecords) {
                                if (record.child_record == child.getRecordID()) {
                                    vaccination_report = Vaccination_Report(record, child.mother, child.village, child.district, child.dob);
                                    break; 
                                }
                            }

                            for (const auto & record : medicalRecords) {
                                if (record.child_record == child.getRecordID()) {
                                    medical_report = Medical_Report(record, child.mother, child.village, child.district, child.dob);
                                    break; 
                                }
                            }

                            while (true) {
                                cout << "#####################################" <<endl;
                                cout << "#         Child Report Menu         #" <<endl;
                                cout << "#####################################" <<endl;
                                cout << "# 1. Display Vaccination Report     #" <<endl;
                                cout << "# 2. Print Vaccination Report       #" <<endl;
                                cout << "# 3. Display Medical Report         #" <<endl;
                                cout << "# 4. Print Medical Report           #" <<endl;
                                cout << "# 5. Logout                         #" <<endl;
                                cout << "#####################################" <<endl;
                                cout << "Select an option: ";

                                int reportChoice;
                                cin >> reportChoice;
                                cin.ignore();

                                if (reportChoice == 5) {
                                    break; 
                                } else if (reportChoice == 1) {
                                    vaccination_report.Display_Generated_Report();
                                } else if (reportChoice == 2) {
                                    char confirm;
                                    cout << "Are you sure you want to print the vaccination report? (y/n): ";
                                    cin >> confirm;
                                    cin.ignore();
                                    if (confirm == 'y' || confirm == 'Y') {
                                        vaccination_report.printReport(child.getRecordID());
                                    } else {
                                        cout << "Print operation cancelled." << endl;
                                    }
                                } else if (reportChoice == 3) {
                                    medical_report.Display_Generated_Report();
                                } else if (reportChoice == 4) {
                                    char confirm;
                                    cout << "Are you sure you want to print the medical report? (y/n): ";
                                    cin >> confirm;
                                    cin.ignore();
                                    if (confirm == 'y' || confirm == 'Y') {
                                        medical_report.printReport(child.getRecordID());
                                    } else {
                                        cout << "Print operation cancelled." << endl;
                                    }
                                } else {
                                    cout << "Invalid option! Please select again." << endl;
                                }
                            }
                        } else {
                            cout << "Invalid password!" << endl;
                        }
                        break;
                    }
                }

            } else if (loginChoice == 2) { 
                string username, password;
                cout << "Enter Username (Full Name): ";
                getline(cin, username);
                cout << "Enter Password (Practice Number): ";
                getline(cin, password);

                for (auto& nurse : nurses) {
                    if (nurse.firstname + " " + nurse.surname == username) {
                        if (password == nurse.practice_number) {
                            cout << "Login successful as Nurse!" << endl;

                            while (true) {
                                cout << "#####################################" <<endl;
                                cout << "#       Nurse Vaccination Menu      #" <<endl;
                                cout << "#####################################" <<endl;
                                cout << "# 1. Capture Vaccination Record     #" <<endl;
                                cout << "# 2. Update Vaccination Record      #" <<endl;
                                cout << "# 3. Delete Vaccination Record      #" <<endl;
                                cout << "# 4. Logout                         #" <<endl;
                                cout << "#####################################" <<endl;
                                cout << "Select an option: ";

                                int nurseChoice;
                                cin >> nurseChoice;
                                cin.ignore();

                                if (nurseChoice == 4) {
                                    break; 
                                } else if (nurseChoice == 1) {
                                    Vaccination V_Record;
                                    V_Record.Capture_Vaccination_Record();
                                    vaccinationRecords.push_back(V_Record);
                                    cout << "Vaccination record captured successfully!" << endl;
                                    V_Record.Display_Vaccination_Records(); 
                                    V_Record.SaveVaccinationRecord();
                                } else if (nurseChoice == 2) {
                                    string recordID;
                                    cout << "Enter Child Record ID to update: ";
                                    getline(cin, recordID);
                                    UpdateVaccinationRecord(vaccinationRecords, recordID);
                                } else if (nurseChoice == 3) {
                                    string recordID;
                                    cout << "Enter Child Record ID to delete: ";
                                    getline(cin, recordID);
                                    DeleteVaccinationRecord(vaccinationRecords, recordID);
                                } else {
                                    cout << "Invalid option! Please select again." << endl;
                                }
                            }
                        } else {
                            cout << "Invalid password!" << endl;
                        }
                        break;
                    }
                }

            } else if (loginChoice == 3) 
            { 
                string username, password;
                cout << "Enter Username (Full Name): ";
                getline(cin, username);
                cout << "Enter Password (Practice Number): ";
                getline(cin, password);

                for (auto& doctor : doctors) {
                    if (doctor.firstname + " " + doctor.surname == username) 
                    {
                        if (password == doctor.practice_number) 
                        {
                            cout << "Login successful as Doctor!" << endl;

                            while (true) 
                            {
                                cout << "#################################" <<endl;
                                cout << "#     Doctor Medical Menu       #" <<endl;
                                cout << "#################################" <<endl;
                                cout << "# 1. Capture Medical Record     #" <<endl;
                                cout << "# 2. Update Medical Record      #" <<endl;
                                cout << "# 3. Delete Medical Record      #" <<endl;
                                cout << "# 4. Logout                     #" <<endl;
                                cout << "#################################" <<endl;
                                cout << "Select an option: ";

                                int doctorChoice;
                                cin >> doctorChoice;
                                cin.ignore();

                                if (doctorChoice == 4) {
                                    break; 
                                } else if (doctorChoice == 1) {
                                    Medical M_Record;
                                    M_Record.Capture_Medical_Record();
                                    medicalRecords.push_back(M_Record);
                                    cout << "Medical record captured successfully!" << endl;
                                    M_Record.DisplayMedicalRecords(); 
                                    M_Record.SaveMedicalRecord();
                                } else if (doctorChoice == 2) {
                                    string recordID;
                                    cout << "Enter Child Record ID to update: ";
                                    getline(cin, recordID);
                                    UpdateMedicalRecord(medicalRecords, recordID);
                                } else if (doctorChoice == 3) {
                                    string recordID;
                                    cout << "Enter Child Record ID to delete: ";
                                    getline(cin, recordID);
                                    DeleteMedicalRecord(medicalRecords, recordID);
                                } else {
                                    cout << "Invalid option! Please select again." << endl;
                                }
                            }
                        } else {
                            cout << "Invalid password!" << endl;
                        }
                        break;
                    }
                }

            } else {
                cout << "Invalid login option!" << endl;
            }
        // search child inforamation
        } else if (choice == 3) {
            while (true) {
                cout << "\n--- Search Child Information ---\n";
                cout << "1. Search by Child Record ID\n";
                cout << "2. Search by Child Name, Surname and DOB\n";
                cout << "3. Back to Main Menu\n";
                cout << "Select an option: ";

                int searchChoice;
                cin >> searchChoice;
                cin.ignore();

                if (searchChoice == 3) {
                    break;

                } else if (searchChoice == 1) {
                    string recordID;
                    cout << "Enter Child Record ID to search: ";
                    getline(cin, recordID);
                    searchMedicalRecords(medicalRecords, recordID);
                    searchVaccinationRecords(vaccinationRecords, recordID);

                } else if (searchChoice == 2) {
                    string firstname, surname, dob;
                    cout << "Enter Child Firstname: ";
                    getline(cin, firstname);
                    cout << "Enter Child Surname: ";
                    getline(cin, surname);
                    
                    do {
                        cout << "Enter Child Date of Birth (dd-mm-yyyy): ";
                        getline(cin, dob);
                        if (!isValidDate(dob)) {
                            cout << "Invalid date format! Please enter a date of length 10." << endl;
                        }
                    } while (!isValidDate(dob));
                    
                    searchByNameAndDOB(children, medicalRecords, vaccinationRecords, firstname, surname, dob);
                } else {
                    cout << "Invalid option! Please select again." << endl;
                }
            }
        } else {
            cout << "Invalid option! Please select again." << endl;
        }
    }
    return 0;
}