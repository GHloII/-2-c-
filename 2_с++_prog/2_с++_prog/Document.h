#pragma once
#include <iostream>
#include <set>
class Document {
public:

	Document();

	// сделать деструктор который находит все остальные связанные документы по айди и удаляет этот оттуда
//	void SetRelatedDocuments(uint32_t id_document);
//	void SetRelatedDocuments(std::set<uint32_t>& set_of_documents);
//	auto GetRelatedDocuments();

	uint32_t GetID();
	std::string GetDocumentFilename();
	std::string GetName();
	std::string GetType();

	void SetName(std::string name);
	void SetType(std::string type);
	void SetDocumentFilename(std::string filename);
	void SetNameFromFilename();

	virtual void Display() = 0;

protected:
	std::string type_; // string?
	uint32_t ID_ = 0;
	std::string document_filename_;
	std::set<uint32_t> related_documents_;
	std::string name_;

};