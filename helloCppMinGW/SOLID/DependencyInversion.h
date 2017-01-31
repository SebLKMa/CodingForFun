/*
 * DependencyInversion.h
 *
 *  Created on: Jan 11, 2017
 *      Author: LMA
 */

#ifndef DEPENDENCYINVERSION_H_
#define DEPENDENCYINVERSION_H_

/**
http://www.tomdalling.com/blog/software-design/solid-class-design-the-dependency-inversion-principle/

The Dependency Inversion Principle (DIP):
High level modules should not depend upon low level modules. Both should depend upon abstractions.

Implementations/subclasses will be used via the abstract interface, not the concrete class interface.

 */

// forwards
class Document;
class Data;
class URL;

//This is the "plug" (abstract base class)
class Exporter
{
public:
	virtual ~Exporter();

    //pure virtual (not implemented)
    virtual std::string convertDocumentToString(Document* pDoc) = 0;
};

//This is a concrete class that implements the "plug"
class CSVExporter : public Exporter
{
public:
    //concrete implementation
	std::string convertDocumentToString(Document* pDoc);
};

//Another concrete class that implements the "plug"
class XMLExporter : public Exporter
{
public:
    //concrete implementation
	std::string convertDocumentToString(Document* pDoc);
};

/**
The ExportController is the "higher level" module and all the Exporter subclasses are the "lower level"
modules. This is because ExportController uses the Exporter subclasses, and not the other way around.
The application of the DIP means that ExportController has no knowledge of CSVExporter, XMLExporter,
or any other Exporter subclass. It only knows about the abstract Exporter interface.
 */

//Class with an Exporter "socket"
class ExportController
{
private:
	Document* _getCurrentDocument();
	std::string _getSaveFilePath();
	void _writeStringToFile(const std::string&, const std::string&);
	Exporter* m_pExporter;
public:
    //this is the socket that accepts Exporter plugs
    void setExporter(Exporter* pExporter)
    {
    	m_pExporter = pExporter;
    }

    void runExport();
};

void ExportController::runExport()
{
    Document* currentDocument = _getCurrentDocument();
    std::string exportedString = m_pExporter->convertDocumentToString(currentDocument);
    std::string exportFilePath = _getSaveFilePath();
    _writeStringToFile(exportedString, exportFilePath);
}

#endif /* DEPENDENCYINVERSION_H_ */
