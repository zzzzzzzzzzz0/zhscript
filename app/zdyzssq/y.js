function rand__(min,max){
	return Math.round((max-min)*Math.random()+min);
}
function yao__(ci){
	document.write("<table border>");
	for(var i0=0;i0++<ci;)
	{
		var hao=[99,99,99,99,99,99,99];
		for(var i=0;i<6;i++){
			for(;;){
				hao[i]=rand__(1,33);
				var b=true;
				for(var i1=0;i1<i;i1++) {
				    if(hao[i1]==hao[i]) {
					    b=false;
				      	break;
				    }
				}
				if(b)
					break;
			}
		}
		hao.sort(function(a,b){
			return a-b;
		});
		hao[6]=rand__(1,16);
		document.write("<tr>");
		for(var i=0;i<hao.length;i++)
			document.write("<td>"+(hao[i]<=9?'0':'')+hao[i]+"</td>");
		document.write("</tr>");
	}
	document.write("</table>");
}
