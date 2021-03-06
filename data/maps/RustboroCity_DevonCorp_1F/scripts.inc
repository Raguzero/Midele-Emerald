RustboroCity_DevonCorp_1F_MapScripts:: @ 8211245
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_1F_OnFrame
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition: @ 821124B
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	compare VAR_RUSTBORO_CITY_STATE, 6
	call_if_eq RustboroCity_DevonCorp_1F_EventScript_TryPositionMicolo
	end

RustboroCity_DevonCorp_1F_OnFrame:
	map_script_2 VAR_TEMP_0, 1, RustboroCity_DevonCorp_1F_EventScript_TryMicoloGiveInfodex
	.2byte 0

RustboroCity_DevonCorp_1F_EventScript_TryPositionMicolo:
	call_if_unset FLAG_SYS_DEXNAV_GET, RustboroCity_DevonCorp_1F_EventScript_PositionMicolo
	return

RustboroCity_DevonCorp_1F_EventScript_PositionMicolo:
	setobjectxyperm 4, 5, 8
	setvar VAR_TEMP_0, 1
	return

RustboroCity_DevonCorp_1F_EventScript_TryMicoloGiveInfodex:
	goto_if_unset FLAG_SYS_DEXNAV_GET, RustboroCity_DevonCorp_1F_EventScript_MicoloGiveInfodex
	end

RustboroCity_DevonCorp_1F_EventScript_MicoloGiveInfodex:
	lockall
	playse SE_KAIDAN
	delay 10
	addobject 4
	applymovement 4, RustboroCity_DevonCorp_1F_Movement_MicoloApproaches1
	waitmovement 0
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, RustboroCity_DevonCorp_1F_Movement_MicoloApproaches2
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_MicoloGiveDexNav, MSGBOX_DEFAULT
	closemessage
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 20
	msgbox RustboroCity_DevonCorp_1F_Text_MicoloGoodBye, MSGBOX_DEFAULT
	closemessage
	applymovement 4, RustboroCity_DevonCorp_1F_Movement_MicoloLeaves
	waitmovement 0
	playse SE_KAIDAN
	delay 10
	removeobject 4
	
	setvar VAR_TEMP_0, 0
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_1F_MICOLO
	releaseall
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs:: @ 8211255
	setobjectxyperm 2, 14, 2
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee:: @ 8211261
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright:: @ 821127F
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered:: @ 8211289
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard:: @ 8211293
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome:: @ 82112BA
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed:: @ 82112C4
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter:: @ 82112CE
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp:: @ 82112F5
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed:: @ 82112FF
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay:: @ 8211309
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay:: @ 8211312
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Movement_MicoloApproaches1:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RustboroCity_DevonCorp_1F_Movement_MicoloApproaches2:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_DevonCorp_1F_Movement_MicoloLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp: @ 821131B
	.string "Hello and welcome to the DEVON\n"
	.string "CORPORATION.\p"
	.string "We're proud producers of items and\n"
	.string "medicine that enhance your life.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed: @ 821138B
	.string "One of our research staff stupidly\n"
	.string "got robbed of an important parcel.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct: @ 82113D1
	.string "Hey, those RUNNING SHOES!\n"
	.string "They're one of our products!\p"
	.string "It makes me happy when I see someone\n"
	.string "using something we made.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright: @ 8211446
	.string "That stolen parcel…\p"
	.string "Well, sure it's important, but it's not\n"
	.string "anything that anyone can use.\p"
	.string "In my estimation, that robber must not\n"
	.string "have been very bright.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered: @ 82114DE
	.string "It sounds like they've recovered\n"
	.string "the ripped-off DEVON GOODS.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter: @ 821151B
	.string "I'm sorry, only authorized people\n"
	.string "are allowed to enter here.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed: @ 8211558
	.string "It's beyond stupid.\n"
	.string "How could we get robbed?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere: @ 8211585
	.string "Hi, there!\n"
	.string "You're always welcome here!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay: @ 82115AC
	.string "Samples of rocks and metal are\n"
	.string "displayed in the glass case.\p"
	.string "There's a panel with some writing\n"
	.string "on it…\p"
	.string "“DEVON CORPORATION got its start as\n"
	.string "a producer of stones from quarries.\p"
	.string "“The company also produced iron from\n"
	.string "filings in the sand.\p"
	.string "“From that humble start as a producer\n"
	.string "of raw materials, DEVON developed.\p"
	.string "“DEVON is now a manufacturer of a wide\n"
	.string "range of industrial products.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay: @ 8211722
	.string "Prototypes and test products fill\n"
	.string "the glass display case.\p"
	.string "There's a panel with a description…\p"
	.string "“In addition to industrial products,\n"
	.string "DEVON now markets sundries and\l"
	.string "pharmaceuticals for better lifestyles.\p"
	.string "“Recently, DEVON has begun marketing\n"
	.string "tools for POKéMON TRAINERS, including\l"
	.string "POKé BALLS and POKéNAV systems.”$"

RustboroCity_DevonCorp_1F_Text_MicoloGiveDexNav:
	.string "MICOLO: hola reina, soy MICOLO n.n\p"
	.string "DARKRAI: ha recuperado las\n"
	.string "PIEZAS DEVON...\p"
	.string "ARCEUS: no pasa nada, ya no son\n"
	.string "necesarias para nuestro plan.\p"
	.string "MOLTRES: que hacemos ahora?\p"
	.string "ARTICUNO: callate, pollo frito.\p"
	.string "MICOLO: xDDDDDDDDDDDDDDDDD\n"
	.string "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\l"
	.string "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\p"
	.string "MICOLO: te he visto derrotar al recluta\n"
	.string "AQUA, eres muy poderoso n.n\p"
	.string "pero te recomiendo que no te metas con\n"
	.string "ellos, son gente peligrosa xDDDD\p"
	.string "aunque si quieres destruirlos puedes\n"
	.string "intentarlo... n.n\p"
	.string "ya sé, te voy a dar este DEXNAV.$"
	

RustboroCity_DevonCorp_1F_Text_MicoloGoodBye:
	.string "MICOLO: con el DEXNAV podras obtener\n"
	.string "POKéMON poderosos para luchar contra\l"
	.string "esos villanos. n.n\p"
	.string "probablemente volvamos a encontrarnos\n"
	.string "n.n\p"
	.string "espero que para ese entonces seas mas\n"
	.string "poderoso.\p"
	.string "ah, y dile a melkor que pague el servidor\n"
	.string "de pokexperto. LOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOL\p"
	.string "recuerda, monociclo porque mono es uno\n"
	.string "y la vida es un ciclo.$"
