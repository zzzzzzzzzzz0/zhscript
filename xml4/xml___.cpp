/*
 * xml___.cpp
 *
 *  Created on: 2010-5-31
 *      Author: zzzzzzzzzzz
 */

#include "xml___.h"
#include "def1.h"
#include "string.h"
#include "for_arg_.h"

xml___::xml___() {
	xmlKeepBlanksDefault(0);
}

xml___::~xml___() {
	if(doc_){
		xmlFreeDoc(doc_);
	}
    xmlCleanupParser();
    xmlMemoryDump();
}

dlle___ xml___* dlln___(xml_from_str__)(const char*str,int argc,...){
	const char *encoding=NULL;
	_for_args( argc )
	{
		switch(i){
		case 0:
			encoding=s;
			break;
		}
	}
	_next_args
	xml___* x=new xml___();
	if(!(x->doc_=xmlReadMemory(str, strlen(str), "", encoding, 0))){
		delete x;
		return NULL;
	}

	return x;
}

dlle___ xml___* dlln___(xml_from_file__)(const char*str,int argc,...){
	const char *encoding=NULL;
	_for_args( argc )
	{
		switch(i){
		case 0:
			encoding=s;
			break;
		}
	}
	_next_args
	xml___* x=new xml___();
	if(!(x->doc_=xmlReadFile(str, encoding, 0))){
		delete x;
		return NULL;
	}

	return x;
}

dlle___ xmlNodePtr dlln___(xml_root__)(xml___*x){
	if(!x)
		return NULL;
	return xmlDocGetRootElement(x->doc_);
}

dlle___ xmlNodePtr dlln___(xml_next__)(xmlNodePtr n){
	if(!n)
		return NULL;
	return n->next;
}

dlle___ xmlNodePtr dlln___(xml_children__)(xmlNodePtr n){
	if(!n)
		return NULL;
	return n->children;
}

dlle___ int dlln___(xml_children_count__)(xmlNodePtr n){
	if(!n)
		return 0;
	int i=0;
	n=n->children;
	for(;n;){
		i++;
		n=n->next;
	}
	return i;
}

dlle___ char* dlln___(xml_node_name__)(xmlNodePtr n){
	if(!n)
		return NULL;
    return (char*)n->name;
}

dlle___ void dlln___(xml_node_text__)(char**addr_ret,xmlNodePtr n,bool all){
    xmlChar * s;
    if(all)
    	s= xmlNodeGetContent(n);
    else
    	s=n->content;
    char*s1=(char*)s;
    if(!s1)
    	return;
    int len=strlen(s1);
    *addr_ret=new char[len+1];
    strcpy(*addr_ret,s1);
    if(all)
    	xmlFree(s);
}

dlle___ int dlln___(xml_has_attr__)(xmlNodePtr n,char*s){
	return xmlHasProp(n,BAD_CAST s)?1:0;
}

dlle___ char* dlln___(xml_get_attr__)(xmlNodePtr n,char*s){
	return (char*)xmlGetProp(n,BAD_CAST s);
}

dlle___ xmlAttrPtr dlln___(xml_attr__)(xmlNodePtr n){
	if(!n)
		return NULL;
	return n->properties;
}

dlle___ xmlAttrPtr dlln___(xml_next_attr__)(xmlAttrPtr a){
	if(!a)
		return NULL;
	return a->next;
}

dlle___ char* dlln___(xml_attr_name__)(xmlAttrPtr a){
	if(!a)
		return NULL;
	return (char*)a->name;
}

dlle___ char* dlln___(xml_attr_text__)(xmlAttrPtr a){
	if(!a)
		return NULL;
    return (char*)a->children[0].content;
}

dlle___ void dlln___(xml_free__)(xml___*x){
	if(!x)
		return;
	delete x;
}
