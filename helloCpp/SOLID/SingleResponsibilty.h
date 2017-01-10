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
class XMLExporter
{
private:
    URL _runSaveDialog();
    String _exportDocumentToXML(Document doc);
    void _showSuccessDialog();
public:
    void exportDocument(Document doc)
    {
        String xmlFileContent = _exportDocumentToXML(doc);
        URL fileURL = _runSaveDialog();
        xmlFileContent.writeToURL(fileURL);
        _showSuccessDialog();
    }
};


#endif /* SINGLERESPONSIBILTY_H_ */
