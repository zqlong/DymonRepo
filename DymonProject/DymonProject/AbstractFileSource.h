//created by Wang Jianwei on 01 Dec 2012
#ifndef ABSTRACTDATASOURCE_H
#define ABSTRACTDATASOURCE_H
#include <string>
#include <fstream>
#include "AbstractDAO.h"

namespace DAO {
	class  AbstractFileSource: public AbstractDAO{

	public:
		AbstractFileSource();
		AbstractFileSource(std::string persistDir, std::string fileName, long fileSize);
		~AbstractFileSource();

		virtual void init();

		virtual char* readRecord();

		virtual void retrieveRecord();
		
		virtual void writeRecord(char* content);

		virtual void appendRecord(char* content);
		
		std::string getFileName();
		virtual void closeDataSource();
		virtual void deleteDataSource();		

	private:	
		std::ifstream _inFile;
		
		std::ofstream _outFile;

		bool isModified;

	protected:
		std::string _fileName;
		std::string _persistDir;
		long _fileSize;
		char* _journal;
	};
}
#endif