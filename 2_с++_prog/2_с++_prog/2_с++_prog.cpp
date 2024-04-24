#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <set>

class Document {
public:
	
	Document() {
		static int counter = 0;
		ID_ = counter;
		counter++;
	}

	// сделать деструктор который находит все остальные связанные документы по айди и удаляет этот оттуда

	auto GetRelatedDocuments() {
		return  related_documents_;
	}
	uint32_t GetID() {
		return ID_;
	}
	auto GetDocumentFilename() {
		return document_filename_;
	}

	void SetRelatedDocuments(uint32_t id_document) {
		related_documents_.insert(id_document);
	}
	void SetRelatedDocuments(std::set<uint32_t>& set_of_documents) {
		for (auto id_to_insert : set_of_documents)
		{
			related_documents_.insert(id_to_insert);
		}
	}
	void SetDocumentFilename(std::string filename) {
		document_filename_ = filename;
	}


protected:
	uint32_t ID_;
	std::string document_filename_;
	std::set<uint32_t> related_documents_;
};

class Letter:public Document {
public:
	std::string adresat;
};



int main()
{
	Letter* letter1 = new Letter;
	Letter* letter2 = new Letter;
	Letter* letter3 = new Letter;
	Letter* letter4 = new Letter;

	std::cout << letter4->GetID();

}

// хранить все в map {id - *Document}