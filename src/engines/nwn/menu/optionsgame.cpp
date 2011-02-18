/* eos - A reimplementation of BioWare's Aurora engine
 * Copyright (c) 2010-2011 Sven Hesse (DrMcCoy), Matthew Hoops (clone2727)
 *
 * The Infinity, Aurora, Odyssey and Eclipse engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 *
 * This file is part of eos and is distributed under the terms of
 * the GNU General Public Licence. See COPYING for more informations.
 */

/** @file engines/nwn/menu/optionsgame.cpp
 *  The game options menu.
 */

#include "engines/nwn/menu/optionsgame.h"

#include "engines/aurora/util.h"

namespace Engines {

namespace NWN {

OptionsGameMenu::OptionsGameMenu() : GUI("options_game") {
	std::list<Widget *> hideTiles;
	hideTiles.push_back(getWidget("NeverBox"));
	hideTiles.push_back(getWidget("AutoBox"));
	hideTiles.push_back(getWidget("AlwaysBox"));
	declareGroup(hideTiles);

	// TODO: Difficulty
	getWidget("DiffSlider", true)->setDisabled(true);

	// TODO: Hide second story tiles setting
	getWidget("NeverBox" , true)->setDisabled(true);
	getWidget("AutoBox"  , true)->setDisabled(true);
	getWidget("AlwaysBox", true)->setDisabled(true);

	// TODO: Violence level
	getWidget("ViolenceSlider", true)->setDisabled(true);

	// TODO: Gore password
	getWidget("PasswordButton", true)->setDisabled(true);

	// TODO: Feedback settings
	getWidget("FeedbackButton", true)->setDisabled(true);
}

OptionsGameMenu::~OptionsGameMenu() {
}

void OptionsGameMenu::callbackActive(Widget &widget) {
	if ((widget.getTag() == "CancelButton") ||
	    (widget.getTag() == "XButton")) {
		_returnCode = 1;
		return;
	}

	if (widget.getTag() == "OkButton") {
		_returnCode = 2;
		return;
	}
}

} // End of namespace NWN

} // End of namespace Engines
