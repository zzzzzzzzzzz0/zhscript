/*
 * sqlite.cpp
 *
 *  Created on: 2011-3-3
 *      Author: zzzzzzzzzzz
 */

#include"def1.h"
#include"call_util.cpp"
#include <sqlite3.h>
#include <stdio.h>

dlle___ void* open__(char*name){
	sqlite3 *db;
	int rc;
	rc = sqlite3_open(name, &db);
	//打开指定的数据库文件,如果不存在将创建一个同名的数据库文件
	if( rc )
	{
		//sqlite3_errmsg(db)
		sqlite3_close(db);
		return 0;
	}
	return db;
}

dlle___ int close__(sqlite3 *db){
	return sqlite3_close(db);
}

dlle___ void exec__(char*buf,long siz,sqlite3 *db,char *sql){
	char *zErrMsg = 0;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	if(zErrMsg)
		cpy__(buf,zErrMsg,siz);
}

void* jsq_;
callback3_2___ cb3_;
dlle___ void dlln___(init__)(void* jsq,callback3_2___ cb){
	jsq_=jsq;
	cb3_=cb;
}

dlle___ void get_table__(int*err,char*buf,long siz,
		void*ce,void* shangji,char*code,
		sqlite3 *db,char *sql,bool head){
	char *zErrMsg = 0;
	int nrow = 0, ncolumn = 0;
	char **azResult; //二维数组存放结果
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	if(zErrMsg){
		cpy__(buf,zErrMsg,siz);
		return;
	}
	const char**argv=new const char*[ncolumn];
	for(int i=head?0:ncolumn ; i<( nrow + 1 ) * ncolumn ;  ){
		for(int i1=0;i1<ncolumn;i1++)
			argv[i1]=azResult[i++];
		cb3_(jsq_,shangji,err,ce,code,false,NULL,ncolumn,argv,0);
		if(*err){
			break;
		}
	}
	delete argv;
	sqlite3_free_table( azResult );
}
