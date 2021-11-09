CONTENTS OF THIS FILE
---------------------

* Introduction
* Requirements
* Installation
* Configuration
* Maintainers


INTRODUCTION
------------

The *Foundation 6 Utils Paragraphs* defines a custom set of Paragraphs used as the basis for content management.
We love the [Zurb Foundation framework](https://get.foundation/), as we use it in almost all of our websites.
To make basic development faster, I've added all the standard paragraphs we use on our websites to this module.
Always check the Zurb Foundation document for any information.


REQUIREMENTS
------------

This module requires the following modules:

* [Paragraphs](https://www.drupal.org/project/paragraphs)
* [Paragraphs Editor Enhancements](https://www.drupal.org/project/paragraphs_ee)
* [Field Group](https://www.drupal.org/project/field_group)
* [Entity Reference Revisions](https://www.drupal.org/project/entity_reference_revisions)
* [Twig Field Value](https://www.drupal.org/project/twig_field_value)
* [Twig Tweak](https://www.drupal.org/project/twig_tweak)
* [Block field](https://www.drupal.org/project/block_field)
* [Views Reference Field](https://www.drupal.org/project/viewsreference)
* [Video Embed Field](https://www.drupal.org/project/video_embed_field)
* [Inline Popup Field Group]()

Please note that you need a custom theme based on Zurb Foundation framework to use this module.
We suggest ZURB Foundation(https://www.drupal.org/project/zurb_foundation) theme as starter theme.


INSTALLATION
------------

Install the Foundation 6 Utils Paragraphs module as you would normally install a contributed Drupal module. Visit https://www.drupal.org/node/1897420 for further information.


CONFIGURATION
-------------
This module needs no configuration. However, you will find two scss files in the *utils* folder.

**spacers.scss** help to manage the top and bottom spaces that are used in the grid system. Please check the file to learn how to use it.

**theme-minimal-styles.scss** give you a basic skeleton to manage the grid and cell background. Please feel free to use it as a starting point in your theme.

For any informations about using the single paragraphs check under.


FAQ
---

**Q: How does *Foundation Grid* paragraph work?**

A: Foundation Grid is the main paragraph of the set, and it is the one you need to manage on your content type. This paragraph makes it easy for you to manage
* Custom ID and custom classes of the grid.
* Both top and bottom spacing, both padding and margin. We define a basic set of spaces (0, 1, 2, 3), but feel free to add more when you need. Use spacers.scss as help to manage them.
* Grid Container type, based on [Zurb Foundation XY Grid](https://get.foundation/sites/docs/xy-grid.html).
* Cell Gutters and Collapse gutters, based on [Zurb Foundation XY Grid](https://get.foundation/sites/docs/xy-grid.html).
* Horizontal and vertical cell alignment, based on [Zurb Foundation Flexbox Utilities](https://get.foundation/sites/docs/flexbox-utilities.html).
* Background, both as image and color. You have an additional checkbox to manage the background as full witdh. Please check theme-minimal-styles.scss for a basic idea to how to manage it.
* Cells, to manage each content inside the grid.


**Q: How does *Foundation Cell* paragraph work?**

A: Foundation Cell is another main paragraph of the set, and makes you define a custom cell in your grid system. This paragraph makes it easy for you to manage
* Custom ID and custom classes of the cell.
* For each standard breakpoint (small, medium and large), the opportunity to define the size and the offset, based on [Zurb Foundation XY Grid](https://get.foundation/sites/docs/xy-grid.html).
* Vertical alignment of the cell, based on [Zurb Foundation Flexbox Utilities](https://get.foundation/sites/docs/flexbox-utilities.html).
* Background, both as image and color. You have two additional checkboxes to manage the background as expand on left or right. Please check theme-minimal-styles.scss for a basic idea to how to manage it.
* Elements, to manage each content inside the cell.


**Q: How does *Text element* paragraph works?**

A: The paragraph give you the opportunity to add a single WYSIWYG text editor in the cell.


**Q: How does *Image* paragraph works?**

A: The paragraph give you the opportunity to add a single image in the cell. The predefined path for the upload is *images/paragraphs/[date:custom:Y]-[date:custom:m]*


**Q: How does *Interchange* paragraph works?**

A: The paragraph give you the opportunity to add a single [Interchange](https://get.foundation/sites/docs/interchange.html) image in the cell. You can manage 3 images, small, medium and large.

The predefined path for the uploads is *images/paragraphs/[date:custom:Y]-[date:custom:m]*


**Q: How does *Accordions* and *Responsive Accordions Tabs* paragraphs works?**

A: These two paragraphs make it easy for you to manage these two elements of Zurb Foundation, both [Accordion](https://get.foundation/sites/docs/accordion.html) and [Responsive Accordion Tabs](https://get.foundation/sites/docs/responsive-accordion-tabs.html).
Please read the official document for the definition of the settings.


**Q: How does *Highlight* paragraph works?**

A: The paragraph allows you to add a single WYSIWYG text editor in the cell, plus the ability to handle custom IDs and custom classes.
We find that there is a need to manage Highlight content with a different style from Text, so we are keeping this content as standard.


**Q: How does *CTA Banner* paragraph works?**

A: The paragraph gives you the opportunity to add a block with the following field
* Custom ID and custom classes
* CTA link
* Title
* Text element as WYSIWYG editor
* Background image
There are always a few CTA banners to deal with, so we keep this content as standard.

\
**Q: How does *Separator* paragraph works?**

A: Sometimes you need to add an empty space, or a stylized space, between different paragraphs.
This paragraph gives you the opportunity to manage it. You can define
* Custom ID and custom classes
* Top and bottom margin. We define a basic set of spaces (0, 1, 2, 3), but feel free to add more when you need. Use spacers.scss as help to manage them.
* Separator type

**Q: How does *Drupal Block*, *Drupal View* and *Video* paragraphs works?**

A: This 3 paragraphs give you the opportunity to manage this standard items.
Please check the related modules for more information
* [Block field](https://www.drupal.org/project/block_field)
* [Views Reference Field](https://www.drupal.org/project/viewsreference)
* [Video Embed Field](https://www.drupal.org/project/video_embed_field)


MAINTAINERS
-----------

* Giovanni Rocchini - https://www.drupal.org/u/grocchini

Supporting organization:

* TourTools - https://www.drupal.org/tourtools
