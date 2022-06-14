 #include <iostream>
 #include <fstream>

 #include "cgicc/CgiDefs.h"
 #include "cgicc/Cgicc.h"
 #include "cgicc/HTTPHTMLHeader.h"
 #include "cgicc/HTMLClasses.h"

 #include "./uuid.hpp"

using namespace cgicc;

int main(int /*argc*/, char ** /*argv*/)
{
    std::cout << "Content-Type:text/plain;charset=utf-8\n\n";

    // Create a new Cgicc object containing all the CGI data
    Cgicc cgi;
    
    // Obtiene el archivo que fue enviado mendiante el formulario.
    const_file_iterator file = cgi.getFile(".pdf");

    form_iterator name      = cgi.getElement("name");
    form_iterator author    = cgi.getElement("author");
    form_iterator topic     = cgi.getElement("topic");

    std::string uniqueID = uuid::generate_uuid_v4();

    std::ofstream saveData("./data.csv", std::ios::app);
    saveData << name->getValue()    << "," 
             << author->getValue()  << "," 
             << topic->getValue()   << ","
             << file->getFilename() << "\n"
             << uniqueID            << "\n";

    saveData.close();
    
    //Creo un archivo con el nombre del mismo...
    std::ofstream saveFile("./uploaded_files/" + uniqueID);
    file->writeToStream(saveFile);
    saveFile.close();    
    
    std::cout << "Su archivo se subio exitosamente" << std::endl;
 
    return 0;
}
