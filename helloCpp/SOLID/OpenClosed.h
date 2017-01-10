/*
 * OpenClosed.h
 *
 *  Created on: Jan 10, 2017
 *      Author: LMA
 */

#ifndef OPENCLOSED_H_
#define OPENCLOSED_H_
#include <iostream>

/**
http://www.tomdalling.com/blog/software-design/solid-class-design-the-open-closed-principle/
The Open Closed Principle (OCP): You should be able to extend a classes behavior, without modifying it.
The OCP is sometimes alternatively defined as:
A class should be open to extension, but closed to modification.
 */

// forwards
class Document;
class Data;
class URL;

// converts document to XML string
class XMLConverter
{
public:
    std::string convertDocumentToXML(const Document& doc);
};

// converts document to binary object
class BinaryConverter
{
public:
    Data convertDocumentToBinary(const Document& doc);
};


/********* DocumentExporter ************/
/**
The DocumentExporter class is not closed to change.
Every time a new export format must be supported, the DocumentExporter class must be modified.
Enums and switch statements are strong indicators that a class is not closed to changes.
If the enum changes, then every related switch statement must also be changed.
*/
enum ConverterType
{
    XMLConverterType,
    BinaryConverterType
};


class DocumentExporter {
private:
    URL _runSaveDialog();
    void _writeToURL(URL url);
    void _showSuccessDialog();

    ConverterType _converterType;
public:
    void setConverterType(const ConverterType& converterType)
    {
    	_converterType = converterType;
    }

    void exportDocument(Document doc)
    {
        URL fileURL = _runSaveDialog();

        switch(_converterType){
            case XMLConverterType:{
                XMLConverter xmlConverter;
                std::string xmlFileContent = xmlConverter.convertDocumentToXML(doc);
                _writeToURL(fileURL);
                break;
            }

            case BinaryConverterType:{
                BinaryConverter binaryConverter;
                Data binaryFileContent = binaryConverter.convertDocumentToBinary(doc);
                _writeToURL(fileURL);
                break;
            }

            default:
                std::cerr << "Unrecognized converter type" << std::endl;
                return;
        }

        _showSuccessDialog();
    }

};


/********* Converter ************/
/**
DocumentExporterOCP is closed to change in respect to new export formats.
To support a new export format, a new class is created that inherits from Converter.
The new converter is injected into DocumentExporterOCP via the setConverter method,
and DocumentExporterOCP is not modified in any way.
 */
class Converter
{
public:
	virtual ~Converter(); // base class MUST have virtual dtor
    virtual Data convertDocumentToData(const Document& doc) = 0;
};

class XMLConverterOCP : public Converter
{
public:
    Data convertDocumentToData(const Document& doc)
    {
        //convert to xml here
    	Data newData;
    	return newData;
    }

};

class BinaryConverterOCP : public Converter {
public:
    Data convertDocumentToData(const Document& doc)
    {
        //convert to binary here
    	Data newData;
    	return newData;
    }
};

/********* DocumentExporter ************/

class DocumentExporterOCP {
private:
    URL _runSaveDialog();
    void _writeToURL(URL url);
    void _showSuccessDialog();
    Converter* _pConverter;
public:
    void setConverter(Converter* converter) //Here is the dependency injection function
    {
    	_pConverter = converter;
    }
    void exportDocument(Document doc);
};

void DocumentExporterOCP::exportDocument(Document doc)
{
    URL fileURL = _runSaveDialog();
    Data fileContent = _pConverter->convertDocumentToData(doc);
    _writeToURL(fileURL);
    _showSuccessDialog();
}

#endif /* OPENCLOSED_H_ */
