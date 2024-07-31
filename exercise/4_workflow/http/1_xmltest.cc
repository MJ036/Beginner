#include "mai.h"
#include "tinyxml2.h"

using namespace tinyxml2;

int main(){
    XMLDocument doc;
    doc.LoadFile("test.xml");
    XMLElement *root = doc.FirstChildElement("sites");
    
    for(XMLElement *site = root->FirstChildElement("site");
        ;
        site = site->NextSiblingElement("site")
       ){
        XMLElement *name = site->FirstChildElement("name");
        XMLElement *url = site->FirstChildElement("url");
        std::cerr << "name:" << name->GetText() << ", url: "
            << url->GetText() << "\n";
    }
    return 0;
}
