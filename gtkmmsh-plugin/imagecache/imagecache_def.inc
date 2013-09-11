void get_imagecache__(const char*buf,imagecache___& ic,void*& ic_arg1){
	long l1,l2;
	sscanf(buf,"%lx|%lx",&l1,&l2);
	ic=(imagecache___)l1;
	ic_arg1=(void*)l2;
}
