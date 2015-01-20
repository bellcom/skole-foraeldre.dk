<?php
/**
 * @file
 * sof_commerce_settings.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function sof_commerce_settings_commerce_product_default_types() {
  $items = array(
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_rates().
 */
function sof_commerce_settings_commerce_tax_default_rates() {
  $items = array(
    'test' => array(
      'name' => 'test',
      'display_title' => 'VAT',
      'description' => '',
      'rate' => 0.25,
      'type' => 'vat',
      'rules_component' => 'commerce_tax_rate_test',
      'default_rules_component' => 1,
      'price_component' => 'tax|test',
      'calculation_callback' => 'commerce_tax_rate_calculate',
      'module' => 'commerce_tax_ui',
      'title' => 'VAT',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_types().
 */
function sof_commerce_settings_commerce_tax_default_types() {
  $items = array(
    'sales_tax' => array(
      'name' => 'sales_tax',
      'display_title' => 'Sales tax',
      'description' => 'A basic type for taxes that do not display inclusive with product prices.',
      'display_inclusive' => 0,
      'round_mode' => 0,
      'rule' => 'commerce_tax_type_sales_tax',
      'module' => 'commerce_tax_ui',
      'title' => 'Sales tax',
      'admin_list' => TRUE,
    ),
    'vat' => array(
      'name' => 'vat',
      'display_title' => 'VAT',
      'description' => 'A basic type for taxes that display inclusive with product prices.',
      'display_inclusive' => 1,
      'round_mode' => 1,
      'rule' => 'commerce_tax_type_vat',
      'module' => 'commerce_tax_ui',
      'title' => 'VAT',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_commerce_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function sof_commerce_settings_default_message_type() {
  $items = array();
  $items['sof_order_admin_message'] = entity_import('message_type', '{
    "name" : "sof_order_admin_message",
    "description" : "SOF Order: Admin message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003ENew Order [message:field-sof-message-order:order-number] at [site:name]\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003ENew Order [message:field-sof-message-order:order-number] at [site:name]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cdiv class=\\u0022message-wrapper\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022header\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022logo\\u0022\\u003E\\u003Ca href=\\u0022[site:url]\\u0022\\u003E[site:site-logo]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022thank-you\\u0022\\u003ENew order has been created\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022body\\u0022\\u003E\\r\\n\\u003Cp\\u003EHere are the details for the order \\u003Ca href=\\u0022http:\\/\\/[message:field-sof-message-order:admin-url]\\u0022\\u003E#[message:field-sof-message-order:order-id]\\u003C\\/a\\u003E, placed on [message:field-sof-message-order:created]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022view-order-status [message:field-sof-message-order:status]\\u0022\\u003E\\u003Ca href=\\u0022http:\\/\\/[message:field-sof-message-order:admin-url]\\u0022\\u003EView order\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022shipping-wrapper\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022ship-to\\u0022\\u003E\\r\\n\\u003Cp\\u003EShip to\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[message:field-sof-message-order:commerce-customer-shipping:commerce_customer_address]\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022ship-method\\u0022\\u003E\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022order-summary-wrapper\\u0022\\u003E\\r\\n\\u003Cp\\u003EItems in the order\\u003C\\/p\\u003E\\r\\n!sof-order-summary\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022message-wrapper\\u0022\\u003E\\n\\u003Cdiv class=\\u0022header\\u0022\\u003E\\n\\u003Cdiv class=\\u0022logo\\u0022\\u003E\\u003Ca href=\\u0022http:\\/\\/sof.workingpropeople.com\\/%5Bsite%3Aurl%5D\\u0022\\u003E[site:site-logo]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022thank-you\\u0022\\u003ENew order has been created\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022body\\u0022\\u003E\\n\\u003Cp\\u003EHere are the details for the order \\u003Ca href=\\u0022http:\\/\\/[message:field-sof-message-order:admin-url]\\u0022\\u003E#[message:field-sof-message-order:order-id]\\u003C\\/a\\u003E, placed on [message:field-sof-message-order:created]\\u003C\\/p\\u003E\\n\\u003Cdiv class=\\u0022view-order-status [message:field-sof-message-order:status]\\u0022\\u003E\\u003Ca href=\\u0022http:\\/\\/[message:field-sof-message-order:admin-url]\\u0022\\u003EView order\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022shipping-wrapper\\u0022\\u003E\\n\\u003Cdiv class=\\u0022ship-to\\u0022\\u003E\\n\\u003Cp\\u003EShip to\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-sof-message-order:commerce-customer-shipping:commerce_customer_address]\\u003C\\/p\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022ship-method\\u0022\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022order-summary-wrapper\\u0022\\u003E\\n\\u003Cp\\u003EItems in the order\\u003C\\/p\\u003E\\n\\u003Cp\\u003E!sof-order-summary\\u003C\\/p\\u003E\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['sof_order_user_message'] = entity_import('message_type', '{
    "name" : "sof_order_user_message",
    "description" : "SOF Order: User message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EOrder [message:field-sof-message-order:order-number] at [site:name]\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EOrder [message:field-sof-message-order:order-number] at [site:name]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cdiv class=\\u0022message-wrapper\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022header\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022logo\\u0022\\u003E\\u003Ca href=\\u0022[site:url]\\u0022\\u003E[site:site-logo]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022thank-you\\u0022\\u003EThank you for your order\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022body\\u0022\\u003E\\r\\n\\u003Cp\\u003EHere are the details for your order \\u003Ca href=\\u0022[[message:message-commerce-order:view-url]\\u0022\\u003E#[message:field-sof-message-order:order-id]\\u003C\\/a\\u003E, placed on [message:field-sof-message-order:created]\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022view-order-status [message:field-sof-message-order:status]\\u0022\\u003E\\u003Ca href=\\u0022[message:message-commerce-order:view-url]\\u0022\\u003EView your order\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022shipping-wrapper\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022ship-to\\u0022\\u003E\\r\\n\\u003Cp\\u003EShip to\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[message:field-sof-message-order:commerce-customer-shipping:commerce_customer_address]\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022ship-method\\u0022\\u003E\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022order-summary-wrapper\\u0022\\u003E\\r\\n\\u003Cp\\u003EItems in your order\\u003C\\/p\\u003E\\r\\n!order-summary\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022message-wrapper\\u0022\\u003E\\n\\u003Cdiv class=\\u0022header\\u0022\\u003E\\n\\u003Cdiv class=\\u0022logo\\u0022\\u003E\\u003Ca href=\\u0022http:\\/\\/sof.workingpropeople.com\\/%5Bsite%3Aurl%5D\\u0022\\u003E[site:site-logo]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022thank-you\\u0022\\u003EThank you for your order\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022body\\u0022\\u003E\\n\\u003Cp\\u003EHere are the details for your order \\u003Ca href=\\u0022http:\\/\\/sof.workingpropeople.com\\/%5B%5Bmessage%3Amessage-commerce-order%3Aview-url%5D\\u0022\\u003E#[message:field-sof-message-order:order-id]\\u003C\\/a\\u003E, placed on [message:field-sof-message-order:created]\\u00a0\\u003C\\/p\\u003E\\n\\u003Cdiv class=\\u0022view-order-status [message:field-sof-message-order:status]\\u0022\\u003E\\u003Ca href=\\u0022http:\\/\\/sof.workingpropeople.com\\/%5Bmessage%3Amessage-commerce-order%3Aview-url%5D\\u0022\\u003EView your order\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022shipping-wrapper\\u0022\\u003E\\n\\u003Cdiv class=\\u0022ship-to\\u0022\\u003E\\n\\u003Cp\\u003EShip to\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-sof-message-order:commerce-customer-shipping:commerce_customer_address]\\u003C\\/p\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022ship-method\\u0022\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022order-summary-wrapper\\u0022\\u003E\\n\\u003Cp\\u003EItems in your order\\u003C\\/p\\u003E\\n\\u003Cp\\u003E!order-summary\\u003C\\/p\\u003E\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
