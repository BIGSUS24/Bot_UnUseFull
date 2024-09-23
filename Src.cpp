#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Function to convert a string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    unordered_map<string, string> memory; // Memory to store user information
    string user_input;

    cout << "Hello! I am just a bot with fixed responses.\n";

    // Main chatbot loop
    while (true) {
        cout << "> "; // Input prompt for the user
        getline(cin, user_input); // Get user input

        // Convert input to lowercase for case-insensitive comparison
        user_input = toLower(user_input);

        // Greetings
        if (user_input == "hi" || user_input == "hello" || user_input == "hey") {
            cout << "Hello there! How can I help you?" << endl;
        }
        // Respond to the question about bot's condition
        else if (user_input == "how are you" || user_input == "are you ok") {
            cout << "I'm just a dumbass bot, but I'm doing great!" << endl;
        }
        // Ask for the user's name
        else if (user_input == "what is my name") {
            if (memory.find("name") != memory.end()) {
                cout << "Your name is: " << memory["name"] << endl;
            } else {
                cout << "You haven't told me your name yet!" << endl;
            }
        }
        // Store the user's name if they provide it
        else if (user_input.find("my name is") != string::npos) {
            size_t pos = user_input.find("my name is");
            string name = user_input.substr(pos + 11); // Extract name from the input
            memory["name"] = name; // Store the name in memory
            cout << "Nice to meet you, " << name << "! I'm still a dumbass bot though." << endl;
        }
        // Goodbye statements to end the conversation
        else if (user_input == "bye" || user_input == "see ya" || user_input == "gn") {
            cout << "Goodbye! I'm just a dumbass bot, but I was happy to chat with you." << endl;
            break; // Exit the loop to end the conversation
        }
        // Default response for unrecognized input
        else {
            cout << "Sorry, I didn't understand that. I'm not coded to handle that level of conversation!" << endl;
        }
    }

    return 0;
}
