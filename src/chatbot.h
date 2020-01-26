#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <iostream>
#include <memory>
#include <string>
#include <wx/bitmap.h>

class GraphNode;
class ChatLogic;

class ChatBot {
private:
    // data handles (owned)
    wxBitmap* _image; // avatar image

    // data handles (not owned)
    GraphNode* _currentNode;
    GraphNode* _rootNode;
    ChatLogic* _chatLogic;

    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    ChatBot(); // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    ChatBot& operator=(ChatBot&& source); // move assignment operator
    ChatBot(ChatBot&& source); // move constructor
    ChatBot(const ChatBot& source); // copy constructor
    ChatBot& operator=(const ChatBot&& source); // copy assignment operator

    void SetCurrentNode(GraphNode* node);
    void SetRootNode(GraphNode* rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic* chatLogic) { _chatLogic = chatLogic; }
    wxBitmap* GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */