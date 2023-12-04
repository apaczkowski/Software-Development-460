// XML Parser Program
// Adding this simple comment to trigger build.  -AP
// Adding commment to debug Nexus checkin.  -AP

#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char** argv) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <XML file>" << std::endl;
        return 1; // Return error code 1 if incorrect arguments
    }

    // Get the XML file path from the command-line arguments
    const char* xmlFilePath = argv[1];

    // Parse the XML file
    xmlDocPtr doc = xmlReadFile(xmlFilePath, NULL, 0);
    if (doc == NULL) {
        std::cerr << "Failed to parse the XML file." << std::endl;
        return 1; // Return error code 1 if parsing fails
    }

    // Get the root element of the XML document
    xmlNodePtr rootNode = xmlDocGetRootElement(doc);

    // Iterate through the child nodes of the root element
    for (xmlNodePtr cur = rootNode->children; cur; cur = cur->next) {
        // Check if the current node is an XML element with the name "book"
        if (cur->type == XML_ELEMENT_NODE && xmlStrcmp(cur->name, (const xmlChar*)"book") == 0) {
            // Iterate through the child nodes of the "book" element
            for (xmlNodePtr bookNode = cur->children; bookNode; bookNode = bookNode->next) {
                // Check if the current node is an XML element with the name "title"
                if (bookNode->type == XML_ELEMENT_NODE && xmlStrcmp(bookNode->name, (const xmlChar*)"title") == 0) {
                    // Get the text content of the "title" element
                    xmlChar* title = xmlNodeListGetString(doc, bookNode->children, 1);

                    // Print the book title
                    std::cout << "Book Title: " << title << std::endl;

                    // Free the allocated memory for the title
                    xmlFree(title);
                }
            }
        }
    }

    // Free the memory allocated for the XML document
    xmlFreeDoc(doc);

    // Cleanup the resources used by the XML parser
    xmlCleanupParser();

    return 0; // Return 0 to indicate successful execution
}
