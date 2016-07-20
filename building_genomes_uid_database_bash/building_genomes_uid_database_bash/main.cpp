//
//  main.cpp
//  building_genomes_uid_database_bash
//
//  Created by Younies Mahmoud on 7/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "headers.h"
#include "configuration.h"
#include "Gi_Uid.hpp"



int main(int argc, const char * argv[]) {
    
    
    Gi_Uid gi_uid(path_to_gi_uid_file);
    
    ifstream file_to_names(path_to_fasta_pathes_file);
    
    string path;
    
    while (getline(file_to_names, path))
    {
        cout << gi_uid.getGiFromFile(path) << endl;
    }
    
    return 0;
}
