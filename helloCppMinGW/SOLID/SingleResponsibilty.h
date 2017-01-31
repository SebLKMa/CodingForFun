/*
 * SingleResponsibilty.h
 *
 *  Created on: Jan 10, 2017
 *      Author: LMA
 */

#ifndef SINGLERESPONSIBILTY_H_
#define SINGLERESPONSIBILTY_H_

// forwards
class URL;
class Document;

/**
 * SOLID design principles
 * http://www.tomdalling.com/blog/software-design/solid-class-design-the-single-responsibility-principle/
 * http://www.tomdalling.com/blog/software-design/solid-class-design-the-open-closed-principle/
 * http://www.tomdalling.com/blog/software-design/solid-class-design-the-liskov-substitution-principle/
 * http://www.tomdalling.com/blog/software-design/solid-class-design-the-interface-segregation-principle/
 * http://www.tomdalling.com/blog/software-design/solid-class-design-the-dependency-inversion-principle/
 *
 */
class XMLExporterMess
{
private:
    URL _runSaveDialog();
    std::string _exportDocumentToXML(const Document& doc);
    void _writeToURL(URL url);
    void _showSuccessDialog();
public:
    void exportDocument(Document doc)
    {
        std::string xmlFileContent = _exportDocumentToXML(doc);
        URL fileURL = _runSaveDialog();
        _writeToURL(fileURL);
        _showSuccessDialog();
    }
};

// XMLExporter takes care of exporting document to XML format only
class XMLConverter {
public:
    std::string convertDocumentToXML(const Document& doc);
};

// XMLExporter, as used by GUI, is not responsible for exporting to XML format
class XMLExporter {
private:
    URL _runSaveDialog();
    void _showSuccessDialog();
    void _writeToURL(URL url);
public:
    void exportDocument(Document doc)
    void XMLExporter::exportDocument(Document doc)
    {
        XMLConverter converter;
        std::string xmlFileContent = converter.convertDocumentToXML(doc);
        URL fileURL = _runSaveDialog();
        _writeToURL(fileURL);
        _showSuccessDialog();
    }
};

#endif /* SINGLERESPONSIBILTY_H_ */
