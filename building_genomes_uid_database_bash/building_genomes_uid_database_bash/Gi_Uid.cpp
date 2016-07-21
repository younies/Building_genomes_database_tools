//
//  Gi_Uid.cpp
//  building_genomes_uid_database_bash
//
//  Created by Younies Mahmoud on 7/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "Gi_Uid.hpp"


Gi_Uid::Gi_Uid(string path_to_giuid_file)
{
    this->path_to_gi_uid_file = path_to_giuid_file;
    
    ifstream file_to_giUID(this->path_to_gi_uid_file);
    if(!file_to_giUID.good())
    {
        cerr << "the gi_uid file is not exist for: " +path_to_giuid_file << endl;
        return;
    }
    
    string line;
    LONGS gi;
    LONGS uid;
    
    while (getline(file_to_giUID, line))
    {
        stringstream liness(line);
        liness >> gi;
        liness >> uid;
        
        this->gi_uid_map.push_back(make_pair(gi, uid));
    }
    
    sort(gi_uid_map.begin(), gi_uid_map.end());
    
    file_to_giUID.close();
    
}





LONGS Gi_Uid::getTheUId(LONGS gi)
{
    LONGS uid = -1;
    //if(binary_search(this->gi_uid_map.begin(), this->gi_uid_map.end(), gi))
      //  return -2;
    
    
    
    LONGS start = 0 , end = this->gi_uid_map.size() - 1 , mid;
    
    
    
    while (end >= start)
    {
        mid = (start + end)/2;
        
        if(this->gi_uid_map[mid].first == gi)
            return this->gi_uid_map[mid].second;
        else if (this->gi_uid_map[mid].first > gi)
            end = mid - 1;
        else
            start = mid + 1;
        
    }
    
    return uid;
    
}






LONGS Gi_Uid::getGiFromFile(string path_to_file)
{
    ifstream file_to_file(path_to_file);
    if(! file_to_file.good())
    {
        cerr << "there is not file for : " + path_to_file << endl;
        return -1;
    }
    
    string line;
    getline(file_to_file, line);
    file_to_file.close();
    
    
    string str_gi;
    stringstream liness(line);
    
    getline(liness, line, '|');
    getline(liness, line, '|');
    stringstream liness2(line);
    LONGS gi;
    liness2 >> gi;
    
    return gi;

}



