new Text:RBTD[100];
enum culori{red, green, blue}
new PlayerText:PreviewColor[MAX_PLAYERS][2];
hook OnPlayerConnect(playerid){
	PreviewColor[playerid][0] = CreatePlayerTextDraw(playerid, 310.999908, 351.363128, "box");
	PlayerTextDrawLetterSize(playerid, PreviewColor[playerid][0], 0.000000, 11.099995);
	PlayerTextDrawTextSize(playerid, PreviewColor[playerid][0], 0.000000, 294.000000);
	PlayerTextDrawAlignment(playerid, PreviewColor[playerid][0], 2);
	PlayerTextDrawColor(playerid, PreviewColor[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, PreviewColor[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, PreviewColor[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, PreviewColor[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, PreviewColor[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, PreviewColor[playerid][0], 255);
	PlayerTextDrawFont(playerid, PreviewColor[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, PreviewColor[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PreviewColor[playerid][0], 0);

	PreviewColor[playerid][1] = CreatePlayerTextDraw(playerid, 313.666687, 417.318511, "-1~n~~r~Red: 255  ~g~Green: 255  ~b~Blue: 255");
	PlayerTextDrawLetterSize(playerid, PreviewColor[playerid][1], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, PreviewColor[playerid][1], 2);
	PlayerTextDrawColor(playerid, PreviewColor[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, PreviewColor[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, PreviewColor[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, PreviewColor[playerid][1], 255);
	PlayerTextDrawFont(playerid, PreviewColor[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, PreviewColor[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, PreviewColor[playerid][1], 0);
}
hook OnGameModeInit(){
	new rainbowcolor[culori];
	rainbowcolor[red] = 255;
	rainbowcolor[blue] = 0;
	rainbowcolor[green] = 0;
	for(new i = 0; i < 100; i++){
		RBTD[i] = TextDrawCreate(25 + float(i) * 6, 243.366714, "box");
		new fincolor = RGBAToHex(rainbowcolor[red], rainbowcolor[green], rainbowcolor[blue], 255);
		TextDrawLetterSize(RBTD[i], 0.000000, 6.000000);
		TextDrawTextSize(RBTD[i], 50.000000, 6.000000);
		TextDrawAlignment(RBTD[i], 2);
		TextDrawColor(RBTD[i], fincolor);
		TextDrawUseBox(RBTD[i], 1);
		TextDrawBoxColor(RBTD[i], fincolor);
		TextDrawSetShadow(RBTD[i], 0);
		TextDrawSetOutline(RBTD[i], 0);
		TextDrawBackgroundColor(RBTD[i], 255);
		TextDrawFont(RBTD[i], 1);
		TextDrawSetProportional(RBTD[i], 1);
		TextDrawSetShadow(RBTD[i], 0);
		TextDrawSetSelectable(RBTD[i], true);
		
		if(rainbowcolor[red] == 255 && rainbowcolor[blue] == 0 && rainbowcolor[green] != 255) rainbowcolor[green] += 15;
		if(rainbowcolor[red] != 0 && rainbowcolor[blue] == 0 && rainbowcolor[green] == 255) rainbowcolor[red] -= 15;
		if(rainbowcolor[red] == 0 && rainbowcolor[blue] != 255 && rainbowcolor[green] == 255) rainbowcolor[blue] += 15;
		if(rainbowcolor[red] == 0 && rainbowcolor[blue] == 255 && rainbowcolor[green] != 0) rainbowcolor[green] -= 15;
		if(rainbowcolor[red] != 255 && rainbowcolor[blue] == 255 && rainbowcolor[green] == 0) rainbowcolor[red] += 15;
		if(rainbowcolor[red] == 255 && rainbowcolor[green] == 0 && rainbowcolor[blue] != 0) rainbowcolor[blue] -= 15;
		//new fincolor = RGBAToHex(rainbowcolor[red], rainbowcolor[green], rainbowcolor[blue], 255);
	}
}
CMD:close(playerid, params[]){
	for(new i; i < 100; i++) TextDrawHideForPlayer(playerid, RBTD[i]);
	PlayerTextDrawHide(playerid, PreviewColor[playerid][0]);
	PlayerTextDrawHide(playerid, PreviewColor[playerid][1]);
	CancelSelectTextDraw(playerid);
	return 1;
}
CMD:colorpicker(playerid, params[]){
	SendClientMessage(playerid, -1, "Type /close to close the color picker");
	for(new i = 0; i < 100; i++) TextDrawShowForPlayer(playerid, RBTD[i]);
	SelectTextDraw(playerid, 0xFF00FFFF);
	return 1;
}
public OnPlayerClickTextDraw(playerid, Text:clickedid){
	for(new i; i < 100; i ++){
		if(clickedid == RBTD[i]){
			new rainbowcolor[culori];
			rainbowcolor[red] = 255;
			rainbowcolor[blue] = 0;
			rainbowcolor[green] = 0;
			for(new u; u <= i; u++){
				
				if(rainbowcolor[red] == 255 && rainbowcolor[blue] == 0 && rainbowcolor[green] != 255) rainbowcolor[green] += 15;
				if(rainbowcolor[red] != 0 && rainbowcolor[blue] == 0 && rainbowcolor[green] == 255) rainbowcolor[red] -= 15;
				if(rainbowcolor[red] == 0 && rainbowcolor[blue] != 255 && rainbowcolor[green] == 255) rainbowcolor[blue] += 15;
				if(rainbowcolor[red] == 0 && rainbowcolor[blue] == 255 && rainbowcolor[green] != 0) rainbowcolor[green] -= 15;
				if(rainbowcolor[red] != 255 && rainbowcolor[blue] == 255 && rainbowcolor[green] == 0) rainbowcolor[red] += 15;
				if(rainbowcolor[red] == 255 && rainbowcolor[green] == 0 && rainbowcolor[blue] != 0) rainbowcolor[blue] -= 15;
				
			}
			new string[128];
			
			new fincolor = RGBAToHex(rainbowcolor[red], rainbowcolor[green], rainbowcolor[blue], 255);
			SendClientMessage(playerid, fincolor, "Your final color looks like this");
			PlayerTextDrawBoxColor(playerid, PreviewColor[playerid][0], fincolor);
			PlayerTextDrawShow(playerid, PreviewColor[playerid][0]);
			PlayerTextDrawShow(playerid, PreviewColor[playerid][1]);
			format(string, 128, "%d~n~~r~Red: %d  ~g~Green: %d  ~b~Blue: %d", fincolor, rainbowcolor[red], rainbowcolor[green], rainbowcolor[blue]);
			PlayerTextDrawSetString(playerid, PreviewColor[playerid][1], string);
		}

	}
	return 1;

}
stock RGBAToHex(r, g, b, a)
{
    return (r<<24 | g<<16 | b<<8 | a);
}
