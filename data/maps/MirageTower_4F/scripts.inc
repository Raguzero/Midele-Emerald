MirageTower_4F_MapScripts:: @ 823AD47
	.byte 0

MirageTower_4F_EventScript_RootFossil:: @ 823AD48
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MirageTower_4F_EventScript_LeaveRootFossil
	giveitem ITEM_ROOT_FOSSIL
	compare VAR_RESULT, FALSE
	call_if_eq MirageTower_4F_EventScript_BagFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject 1
	delay 30
	setflag FLAG_CHOSE_ROOT_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveRootFossil:: @ 823AD7F
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil:: @ 823AD89
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MirageTower_4F_EventScript_LeaveClawFossil
	giveitem ITEM_CLAW_FOSSIL
	compare VAR_RESULT, FALSE
	call_if_eq MirageTower_4F_EventScript_BagFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	removeobject 2
	delay 30
	setflag FLAG_CHOSE_CLAW_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end
	
MirageTower_4F_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	closemessage
	end

MirageTower_4F_EventScript_LeaveClawFossil:: @ 823ADC0
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower:: @ 823ADCA
	release
	end

    @ Combate contra totem.
MirageTower_4F_EventScript_Totem:: @ 8237725
	lockall
	playmoncry SPECIES_COFAGRIGUS, 2
	delay 40
	waitmoncry
	msgbox MirageTower_4F_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_COFAGRIGUS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 4
	setflag FLAG_TOTEM_MIRAGETOWER
    msgbox MirageTower_4F_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	

MirageTower_4F_Text_TakeRootFossil: @ 823ADF9
	.string "You found the ROOT FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ROOT FOSSIL anyway?$"

MirageTower_4F_Text_LeftRootFossilAlone: @ 823AE79
	.string "{PLAYER} left the ROOT FOSSIL alone.$"

MirageTower_4F_Text_TakeClawFossil: @ 823AE98
	.string "You found the CLAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the CLAW FOSSIL anyway?$"

MirageTower_4F_Text_LeaveClawFossilAlone: @ 823AF18
	.string "{PLAYER} left the CLAW FOSSIL alone.$"
	
MirageTower_4F_Text_Totemaparece:
	.string "COFAGRIGUS, the Totem Pokémon of\n" 
	.string "Mirage Tower, has appeared!$"
	
MirageTower_4F_Text_Totemderrotado:
	.string "COFAGRIGUS disappeared...$"


