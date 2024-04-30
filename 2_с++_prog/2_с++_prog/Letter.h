#pragma once
#include <iostream>
#include <string>

#include "Document.h"

class Letter :public Document {
public:
	void SetAddressee(std::string addressee) {
		addressee_ = addressee;
	}
	void SetSender(std::string sender) {
		sender_ = sender;
	}
	auto GetAddressee() {
		return addressee_;
	}
	auto GetSender() {
		return sender_;
	}
	void Display() override {
		std::cout << type_ << " " << name_ << " " << document_filename_ << " " << addressee_ << " " << sender_ << " ";
	}
private:

	std::string addressee_; //получатель
	std::string sender_; //отправитель

};



