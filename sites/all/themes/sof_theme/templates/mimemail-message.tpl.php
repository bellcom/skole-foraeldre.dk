<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[module]--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <?php if ($css): ?>
    <style type="text/css">
      p {
        font-size: 18px;
        color: #000;
      }
      table {
        border: none;
        margin: 10px 0px;
        padding: 0px;
        width: 100%;
      }
      table td th {
        border-bottom: 0px none;
        margin: 0px;
        padding: 5px 7px;
      }
      table th {
        background-color: #00A2EB;
        color: #FFF;
        text-transform: uppercase;
        border-right: 3px solid #FFF;
        border-radius: 7px;
        font-weight: normal;
      }
      table td {
        background: none repeat scroll 0% 0% #F0F0F0;
        border-top: 3px solid #FFF;
        border-right: 3px solid #FFF;
        border-radius: 7px;
        color: #5E5E5E;
      }
    </style>
    <?php endif; ?>
  </head>
  <body id="mimemail-body" <?php if ($module && $key) : print 'class="' . $module . '-' . $key . '"'; endif; ?>>
    <div id="center">
      <div id="main">
        <?php print $body ?>
      </div>
    </div>
  </body>
</html>
