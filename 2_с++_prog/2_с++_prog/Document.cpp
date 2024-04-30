#include "Document.h"
#include <iostream>

Document::Document() {

}
//auto Document::GetRelatedDocuments() {
//	return  related_documents_;
//}
//void Document::SetRelatedDocuments(uint32_t id_document) {
//	related_documents_.insert(id_document);
//}
//void Document::SetRelatedDocuments(std::set<uint32_t>& set_of_documents) {
//	for (auto id_to_insert : set_of_documents)
//	{
//		related_documents_.insert(id_to_insert);
//	}
//}
uint32_t Document::GetID() {
	return ID_;
}
std::string Document::GetDocumentFilename() {
	return document_filename_;
}
void Document::SetDocumentFilename(std::string filename) {
	document_filename_ = filename;
}

std::string Document::GetName() {
	return name_;
}
void Document::SetName(std::string name) {
	name_ = name;
}

std::string Document::GetType() {
	return type_;
}
void Document::SetType(std::string type) {
	type_ = type;
}




//fielname: 
// ./text.txt
// name 
//  text
void Document::SetNameFromFilename() {
	for (size_t i = 0; i < document_filename_.size(); i++)
	{
		if (document_filename_[i] == '/') {
			for (size_t j = i+1; j < document_filename_.size(); j++)
			{
				if (document_filename_[j] == '.') return;

				name_.push_back(document_filename_[j]);
			}
		}
	}
}