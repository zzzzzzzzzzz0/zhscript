/*
 * path.h
 *
 *  Created on: 2010-3-12
 *      Author: zzzzzzzzzzz
 */

#ifndef PATH_H_
#define PATH_H_
#include <string>
using namespace std;

bool get_path__(const string& path,string&buf);
bool mk_abs_path__(const string& path, string& path2);

#endif /* PATH_H_ */
