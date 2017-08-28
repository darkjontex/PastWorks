//Variáveis globais
var screen; //tela
var tolerancia = 7; //tamanho da "caixa de selecao" em pixels
var idgen = -1; //gerador de ids dos objetos

{//Objeto Vertice (par ordenado dos pontos/vertices)
function Vertice(x,y){
	this.getX = function(){return x;}
	this.getY = function(){return y;}
	this.trans = function(matriz){
		var result = [];
		result[0] = matriz[0][0] * x + matriz[0][1] * y + matriz[0][2];
		result[1] = matriz[1][0] * x + matriz[1][1] * y + matriz[1][2];
		result[2] = matriz[2][0] * x + matriz[2][1] * y + matriz[2][2];
		x = result[0]/result[2];
		y = result[1]/result[2];
	}
}
Vertice.prototype.toString = function(){return "(" + this.getX() + "," + this.getY() + ")";}
}

{//Objeto Ponto
function Point(coord, color){
	var drawID = idgen+1;
	idgen++;
	this.getID = function(){return drawID;}
	this.getCoord = function(){return coord;}
	this.getColor = function(){return color;}
}	
Point.prototype.draw = function(ctx){
	ctx.save();
	ctx.fillStyle = this.getColor();
	ctx.fillRect(this.getCoord().getX()-1,this.getCoord().getY()-1,3,3);
	ctx.restore();
	}
Point.prototype.pick = function(mouseCoord){
	if ((mouseCoord.getX() > this.getCoord().getX() - tolerancia) && (mouseCoord.getX() < this.getCoord().getX() + tolerancia)){
		if ((mouseCoord.getY() > this.getCoord().getY() - tolerancia) && (mouseCoord.getY() < this.getCoord().getY() + tolerancia)){
			return true;
		}
	}
	return false;
}
Point.prototype.transform = function(matriz){this.getCoord().trans(matriz);}
Point.prototype.toString = function(){return "Ponto " + this.getCoord() + " " + this.getColor();}
}

{//Objeto Linha
function Line(vert1, vert2, color){
	var drawID = idgen+1;
	idgen++;
	this.getID = function(){return drawID;}
	this.getV1 = function(){return vert1;}
	this.getV2 = function(){return vert2;}
	this.getColor = function(){return color;}
}
Line.prototype.draw = function(ctx){
	ctx.save();
	ctx.strokeStyle = this.getColor();
	ctx.lineWidth = 1;
	ctx.beginPath();
	ctx.moveTo(this.getV1().getX(),this.getV1().getY());
	ctx.lineTo(this.getV2().getX(),this.getV2().getY());
	ctx.stroke();
	ctx.closePath();
	ctx.restore();
}
Line.prototype.pickCode = function(vertX, vertY, mouseCoordX, mouseCoordY){
	var code = new Array();
	code[0] = vertX < mouseCoordX - tolerancia;
	code[1] = vertX > mouseCoordX + tolerancia;
	code[2] = vertY < mouseCoordY - tolerancia;
	code[3] = vertY > mouseCoordY + tolerancia;
	return code;
}
Line.prototype.pick = function(mouseCoord){
	var x1 = this.getV1().getX();
	var y1 = this.getV1().getY();
	var x2 = this.getV2().getX();
	var y2 = this.getV2().getY();
	
	var code1;
	var code2 = this.pickCode(x2, y2, mouseCoord.getX(), mouseCoord.getY());
	
	do{
		code1 = this.pickCode(x1, y1, mouseCoord.getX(), mouseCoord.getY());
		
		for (var i=0;i<4;i++) if (code1[i] && code2[i]) break; //teste pick não trivial
		if (i!=4) break;
		
		//mover ponto 1 para limite da janela
		if (code1[0]){
			y1 += (mouseCoord.getX() - tolerancia - x1) * (y2 - y1) / (x2 - x1);
			x1 = mouseCoord.getX() - tolerancia;
		}else if (code1[1]){
			y1 += (mouseCoord.getX() + tolerancia - x1) * (y2 - y1) / (x2 - x1);
			x1 = mouseCoord.getX() + tolerancia;
		}else if (code1[2]){
			x1 += (mouseCoord.getY() - tolerancia - y1) * (x2 - x1) / (y2 - y1);
			y1 = mouseCoord.getY() - tolerancia;
		}else if (code1[3]){
			x1 += (mouseCoord.getY() + tolerancia - y1) * (x2 - x1) / (y2 - y1);
			y1 = mouseCoord.getY() + tolerancia;
		}else return true;
	}while(true);
	return false;
}
Line.prototype.transform = function(matriz){this.getV1().trans(matriz); this.getV2().trans(matriz);}
Line.prototype.toString = function(){return "Linha " + this.getV1() + " " + this.getV2() + " " + this.getColor();}
}

{//Objeto Polígono
function Poligon(vertList, color){
	var drawID = idgen+1;
	idgen++;
	this.getID = function(){return drawID;}
	this.getVertList = function(){return vertList;}
	this.getColor = function(){return color;}
}
Poligon.prototype.draw = function(ctx){
	var vList = this.getVertList();
	ctx.save();
	ctx.strokeStyle = this.getColor();
	ctx.beginPath();
	ctx.moveTo(vList[0].getX(),vList[0].getY());
	for (var i in vList) ctx.lineTo(vList[i].getX(),vList[i].getY());
	ctx.closePath();
	ctx.stroke();
	ctx.restore();
}
Poligon.prototype.pick = function(mouseCoord){
	var ni = 0; //numero de intersecções
	var p1;
	var p2;
	var vList = this.getVertList();
	
	for (var i=0;i<vList.length;i++){
		p1 = vList[i];
		if (i<vList.length-1) p2 = vList[i+1];
		else p2 = vList[0];
		
		if (!(p1.getY() == p2.getY()) && //descarta horizontais
			!((p1.getY() > mouseCoord.getY())&&(p2.getY() > mouseCoord.getY())) && //descarta retas acima
			!((p1.getY() < mouseCoord.getY())&&(p2.getY() < mouseCoord.getY())) && //descarta retas abaixo
			!((p1.getX() < mouseCoord.getX())&&(p2.getX() < mouseCoord.getX()))) //descarta retas a esquerda
		{
			if (p1.getY() == mouseCoord.getY()){ //primeiro ponto na mesma cota
				if ((p1.getX() > mouseCoord.getX()) && (p2.getY() > mouseCoord.getY())) ni++; //a direita e acima do ponto
			}else{
				if (p2.getY() == mouseCoord.getY()){ //segundo ponto na mesma cota
					if ((p2.getX() > mouseCoord.getX()) && (p1.getY() > mouseCoord.getY())) ni++; //a direita e acima do ponto
				}else{
						if ((p1.getX() > mouseCoord.getX()) && (p2.getX() > mouseCoord.getX())) ni++; //inteiramente a direita
					else{ //verifica ponto de intersecção
						var dx = p1.getX() - p2.getX();
						var xc = p1.getX();
						if (dx != 0) xc += (mouseCoord.getY() - p1.getY()) * dx / (p1.getY() - p2.getY());
						if (xc > mouseCoord.getX()) ni++;
					}
				}
			}
		}
	}
	return (!(ni%2==0));
}
Poligon.prototype.transform = function(matriz){for (var i in this.getVertList()) this.getVertList()[i].trans(matriz);}
Poligon.prototype.toString = function(){
	var vList = this.getVertList();
	var str = "Poligono ";
	for (var i in vList) str = str + " " + vList[i];
	return str + " " + this.getColor();
}
}

{//Objeto Curva de Bezier
function Bezier(vert1,vert2,ctrl1,ctrl2,color){
	var drawID = idgen+1;
	idgen++;
	this.getID = function(){return drawID;}
	this.getV1 = function(){return vert1;}
	this.getV2 = function(){return vert2;}
	this.getC1 = function(){return ctrl1;}
	this.getC2 = function(){return ctrl2;}
	this.getColor = function(){return color;}
}
Bezier.prototype.draw = function(ctx){
	ctx.save();
	ctx.strokeStyle = this.getColor();
	ctx.lineWidth = 1;
	ctx.beginPath();
	ctx.moveTo(this.getV1().getX(),this.getV1().getY());
	ctx.bezierCurveTo(this.getC1().getX(),this.getC1().getY(),this.getC2().getX(),this.getC2().getY(),this.getV2().getX(),this.getV2().getY());
	ctx.stroke();
	ctx.closePath();
	ctx.restore();
};
Bezier.prototype.pick = function(mouseCoord){
	if ((mouseCoord.getX() > this.getV1().getX() - tolerancia) && (mouseCoord.getX() < this.getV1().getX() + tolerancia)){
		if ((mouseCoord.getY() > this.getV1().getY() - tolerancia) && (mouseCoord.getY() < this.getV1().getY() + tolerancia)){
			return true;
		}
	}
	if ((mouseCoord.getX() > this.getV2().getX() - tolerancia) && (mouseCoord.getX() < this.getV2().getX() + tolerancia)){
		if ((mouseCoord.getY() > this.getV2().getY() - tolerancia) && (mouseCoord.getY() < this.getV2().getY() + tolerancia)){
			return true;
		}
	}
	return false;
}
Bezier.prototype.transform = function(matriz){
	this.getV1().trans(matriz);
	this.getV2().trans(matriz);
	this.getC1().trans(matriz);
	this.getC2().trans(matriz);
}
Bezier.prototype.toString = function(){
	var str = "Bezier ";
	str = str + this.getV1() + " " + this.getV2() + " " + this.getC1() + " " + this.getC2();
	return str + " " + this.getColor();
}
}

function Screen(){
	var canvas = document.getElementById("canvas");
	var ctx = canvas.getContext("2d");
	var colorpicker = document.getElementById("colorpicker");
	var objectList = []; //lista principal de objetos
	var rubberband = false; //rubberband de linha e poligono
	var b_rubberband = false; //rubberband de curva de bezier
	var tempVertList = []; //lista de vertices temporários das rubberbands
	var selectedObject = -2; //ID do objeto selecionado
	
	this.getMousePos = function(event){ //pega posição atual do mouse
		//pega posição do canvas em relação à página
		var obj = canvas;
		var top = 0;
		var left = 0;
		while (obj && obj.tagName != 'BODY') {
			top += obj.offsetTop;
			left += obj.offsetLeft;
			obj = obj.offsetParent;
		}
		//retorna a posição do mouse em relação ao canvas
		var mouseX = event.clientX - left + window.pageXOffset;
		var mouseY = event.clientY - top + window.pageYOffset;
		return new Vertice(mouseX, mouseY);
	}
	
	//Métodos do Fecho convexo
	var getFarthestVert = function(vert1,vert2,vertList){
		var maxD = 0;
		var maxVert = new Array();
		var newVertList = new Array();
		for (var i in vertList){
			var vert = vertList[i];
			var Vy = vert2.getX() - vert1.getX();
			var Vx = vert1.getY() - vert2.getY();
			var d = Vx * (vert.getX()-vert1.getX()) + Vy * (vert.getY()-vert1.getY());
			
			if (d>0){newVertList.push(vert);}
			else continue;
			if (d>maxD){maxD=d; maxVert=vert;}
		}
		return {'maxVert':maxVert, 'newVertList':newVertList};
	}
	var quickHull = function(vert1, vert2, vertList){
		var baseLines = new Array();
		var t = getFarthestVert(vert1,vert2,vertList);
		if (t.maxVert.length==undefined){ // if there is still a point "outside" the base line
			baseLines = baseLines.concat(quickHull(vert1,t.maxVert,t.newVertList));
			baseLines = baseLines.concat(quickHull(t.maxVert,vert2,t.newVertList));
			return baseLines;
		}else{// if there is no more point "outside" the base line, the current base line is part of the convex hull
			return [vert1,vert2];
		}
	}
	this.startQuickHull = function(){
		var vertList = [];
		for (var i in objectList){
			if (objectList[i].constructor == Point) vertList.push(objectList[i].getCoord());
			else if (objectList[i].constructor == Line){
				vertList.push(objectList[i].getV1());
				vertList.push(objectList[i].getV2());
			}else if (objectList[i].constructor == Poligon) vertList = vertList.concat(objectList[i].getVertList());
		}
		var maxX, minX;
		var maxVert, minVert;
		for (var i in vertList){
			var pt = vertList[i];
			if (pt.getX() > maxX || !maxX) {
				maxVert = pt;
					maxX = pt.getX();
			}
			if (pt.getX() < minX || !minX) {
				minVert = pt;
				minX = pt.getX();
			}
		}
		var convexHull = [].concat(quickHull(minVert,maxVert,vertList), quickHull(maxVert,minVert,vertList));
		
		ctx.strokeStyle = 'RED';
		ctx.beginPath();
		ctx.moveTo(convexHull[0].getX(),convexHull[0].getY());
		for (var i=1;i<convexHull.length;i++) ctx.lineTo(convexHull[i].getX(),convexHull[i].getY());
		ctx.closePath();
		ctx.stroke();
	}
	
	//Métodos de desenho
	this.redraw = function(){
		ctx.clearRect(0,0,canvas.width, canvas.height); //limpa a tela
		for (var i in objectList) objectList[i].draw(ctx); //desenha todos os objetos
		if (document.getElementById('convexhull').checked) this.startQuickHull();
	}
	this.drawRubberband = function(event){
		var mouse = this.getMousePos(event)
		if (rubberband || b_rubberband){
			this.redraw();
			ctx.save();
			ctx.strokeStyle = colorpicker.value;
			ctx.lineWidth = 1;
			ctx.beginPath();
			ctx.moveTo(tempVertList[0].getX(),tempVertList[0].getY());
			if (rubberband){
				for (i=1;i<tempVertList.length;i++) ctx.lineTo(tempVertList[i].getX(),tempVertList[i].getY());
				ctx.lineTo(mouse.getX(),mouse.getY());
			}else{
				var v2 = tempVertList[1] || mouse;
				var c1 = tempVertList[2] || mouse;
				var c2 = tempVertList[3] || mouse;
				ctx.bezierCurveTo(c1.getX(),c1.getY(),c2.getX(),c2.getY(),v2.getX(),v2.getY());
			}
			ctx.stroke();
			ctx.closePath();
			ctx.restore();
		}
	}
	this.insertPoint = function(event){
		objectList.push(new Point(this.getMousePos(event),colorpicker.value));
		this.redraw();
	}
	this.insertLine = function(event){
		if (rubberband == false && b_rubberband == false){
			tempVertList[0] = this.getMousePos(event);
			rubberband = true;
		}else if (rubberband==true && b_rubberband == false){
			rubberband = false;
			objectList.push(new Line(tempVertList[0],this.getMousePos(event),colorpicker.value));
			tempVertList.pop();
			this.redraw();
		}
	}
	this.insertPoligon = function(event){
		if (rubberband == false && b_rubberband == false){
			tempVertList[0] = this.getMousePos(event);
			rubberband = true;
		}else if (rubberband==true && b_rubberband == false){
			if (event.ctrlKey==true)tempVertList.push(this.getMousePos(event));
			else{
				tempVertList.push(this.getMousePos(event));
				objectList.push(new Poligon(tempVertList,colorpicker.value));
				tempVertList = [];
				rubberband = false;
				this.redraw();
			}
		}
	}
	this.insertBezier = function(event){
		if (b_rubberband == false && rubberband == false){
			tempVertList[0] = this.getMousePos(event);
			b_rubberband = true;
		}else if (b_rubberband == true && rubberband == false){
			if (tempVertList.length == 3){
				objectList.push(new Bezier(tempVertList[0],tempVertList[1],tempVertList[2],this.getMousePos(event),colorpicker.value));
				tempVertList = [];
				b_rubberband = false;
				this.redraw();
			}else tempVertList.push(this.getMousePos(event));
		}
	}
	
	//Método de selecao
	this.pick = function(event){
		for (var i=objectList.length-1;i>=0;i--) if (objectList[i].pick(this.getMousePos(event))==true){ alert(objectList[i]); break;}
		selectedObject = objectList[i].getID();
	}
	
	//Método de transformação linear
	this.transform = function(){
		if (selectedObject >= 0){
			var tx = new Number(document.getElementById("transx").value).valueOf();
			var ty = new Number(document.getElementById("transy").value).valueOf();
			var sx = new Number(document.getElementById("escalax").value || document.getElementById("escalax").placeholder).valueOf();
			var sy = new Number(document.getElementById("escalay").value || document.getElementById("escalay").placeholder).valueOf();
			var angulo = new Number(document.getElementById("angulo").value).valueOf();
			var seno = Math.sin(angulo.valueOf()*Math.PI/180);
			var cosseno = Math.cos(angulo.valueOf()*Math.PI/180);
			var espelharX, espelharY;
			if (document.getElementById("espelharX").checked) espelharX = -1;
			else espelharX = 1;
			if (document.getElementById("espelharY").checked) espelharY = -1;
			else espelharY = 1;
			var matriz = [[espelharY*sx*cosseno,(-1)*sx*seno,sx*tx],[sy*seno,espelharX*sy*cosseno,sy*ty],[0,0,1]];
			for (var i in objectList)
				if (objectList[i].getID() == selectedObject){
					objectList[i].transform(matriz);
					break;
				}
			this.redraw();
		}else alert("Selecione alguma coisa!");
	}
	
	
	
	//Métodos da interface
	this.click = function(event){ //seletor de operação
		var op = document.getElementById('operation');
		if (op.value == 'point') this.insertPoint(event);
		else if (op.value == 'line') this.insertLine(event);
		else if (op.value == 'poligon') this.insertPoligon(event);
		else if (op.value == 'bezier') this.insertBezier(event);
		else if (op.value == 'pick') this.pick(event);
	}
	this.deselecionar = function(){
		selectedObject = -10;
	}
	this.listarObjetos = function(){
		var str = "";
		for (var i in objectList){
			str = str + objectList[i];
			if (objectList[i].getID() == selectedObject) str = str + " SELECIONADO";
			str = str + "\n";
		}
		alert (str);
	}
	this.limitInput = function(e){ //faz com que só receba numeros nos campos de tranfomação
		var tecla=(window.event)?event.keyCode:e.which;   
		if((tecla>47 && tecla<58)) return true;
		else if (tecla==8 || tecla==0 || tecla==189 || tecla==190) return true;
		else return false;
	}
	this.salvarImagem = function(){
		canvas.toBlob(function(blob) {
			saveAs(blob, "teste.png");
		},"image/png");
	}
	this.salvarTexto = function(){
		var arq=[];
		for (var i=0;i<objectList.length-1;i++) arq.push(objectList[i] + "\r\n");
		arq.push(objectList[objectList.length-1]);
		(function (view){
			get_blob = function() {
				return view.Blob;
			}
			var bb = get_blob();
			var blob = new bb(arq, {type: "text/plain;charset=" + document.characterSet});
			saveAs(blob, "teste.txt");
		}(self));
	}
	this.carregar = function(event){
		var file = event.target.files;
		var reader = new FileReader();
		reader.onloadend = function(e){
			var newObjectList = [];
			var list = this.result.split("\r\n");
			for (var i in list){
				var str = list[i].split(" ");
				switch(str[0]){
					case "Ponto":{
						var vert = str[1].replace("("," ").replace(")"," ").split(",");
						var x = new Number(vert[0]).valueOf();
						var y = new Number(vert[1]).valueOf();
						newObjectList.push(new Point(new Vertice(x,y),str[2]));
						break;
					}
					case "Linha":{
						var vert = str[1].replace("("," ").replace(")"," ").split(",");
						var x1 = new Number(vert[0]).valueOf();
						var y1 = new Number(vert[1]).valueOf();
						var vert = str[2].replace("("," ").replace(")"," ").split(",");
						var x2 = new Number(vert[0]).valueOf();
						var y2 = new Number(vert[1]).valueOf();
						newObjectList.push(new Line(new Vertice(x1,y1),new Vertice(x2,y2),str[3]));
						break;
					}
					case "Poligono":{
						var vList = [];
						for (var j=1;j<str.length-1;j++){
							var vert = str[j].replace("("," ").replace(")"," ").split(",");
							var x = new Number(vert[0]).valueOf();
							var y = new Number(vert[1]).valueOf();
							vList.push(new Vertice(x,y));
						}
						newObjectList.push(new Poligon(vList,str[str.length-1]));
						break;
					}
					case "Bezier":{
						var vert = str[1].replace("("," ").replace(")"," ").split(",");
						var x1 = new Number(vert[0]).valueOf();
						var y1 = new Number(vert[1]).valueOf();
						var vert = str[2].replace("("," ").replace(")"," ").split(",");
						var x2 = new Number(vert[0]).valueOf();
						var y2 = new Number(vert[1]).valueOf();
						var vert = str[3].replace("("," ").replace(")"," ").split(",");
						var x3 = new Number(vert[0]).valueOf();
						var y3 = new Number(vert[1]).valueOf();
						var vert = str[4].replace("("," ").replace(")"," ").split(",");
						var x4 = new Number(vert[0]).valueOf();
						var y4 = new Number(vert[1]).valueOf();
						newObjectList.push(new Bezier(new Vertice(x1,y1),new Vertice(x2,y2),new Vertice(x3,y3),new Vertice(x4,y4),str[5]));
						break;
					}
				}
			}
			objectList = newObjectList;
		};
		reader.readAsText(file[0]);
		this.redraw();
	}
}