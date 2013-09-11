名为“优先攻击弱者策略”。
（参数：nvjiangs,bingqi_cnt）
代码为下代码
	nvjiangs.sort(function compare(a,b){
		return a.xue_-b.xue_;
	});
	if(nvjiangs.length>bingqi_cnt)
		nvjiangs.splice(bingqi_cnt);
	return nvjiangs;
上代码。
