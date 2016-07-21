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
    
    ofstream output_bash(path_to_bash_file);
    
    output_bash << "#!/bin/bash \n\n";
    
    

    
    while (getline(file_to_names, path))
    {
        LONGS uid =  gi_uid.getGiFromFile(path) ;
        if(uid < 0 )
        {
            cout << "there are problem with file: " + path << endl;
        }
        else
        {
            output_bash << "cat  " << path << "  >>  " << genomesDatabases << uid << ".fa" << endl;
        }
    }
    
    output_bash.flush();
    output_bash.close();
    
    return 0;
}
