#include <dirent.h>
#include <string>

#include "List.hpp"
#include "Employment.hpp"

Employment* AllFilesInDirectory(std::string path) {
	struct dirent *entry;
	DIR *dp;

	// Open the directory containing the data
	dp = opendir(path.c_str());
	if (dp == NULL) {
		perror("opendir");
		return (Employment *)NULL;
	}

	std::string base(path);
	base += "/";
	Employment* head = (Employment *)NULL;

	Employment* tempEmp = new Employment("",0,0,0,NULL); //NEW

	while ((entry = readdir(dp))) {
		if (entry->d_name[0] != '.') {
			std::string filename = base + (std::string) entry->d_name;

			/* Create your linked-lists with 
			   build_empl_list() and append_lists()
			   */
			   Employment * build = build_empl_list(filename); //NEW
			   head = append_lists(tempEmp, build); //NEW

		}
	}
	closedir(dp);
	return head;
}
