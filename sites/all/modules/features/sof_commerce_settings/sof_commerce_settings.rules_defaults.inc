<?php
/**
 * @file
 * sof_commerce_settings.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function sof_commerce_settings_default_rules_configuration() {
  $items = array();
  $items['commerce_checkout_sof_update_public_order_status'] = entity_import('rules_config', '{ "commerce_checkout_sof_update_public_order_status" : {
      "LABEL" : "Sof Update the order status on checkout completion public",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce_order", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "commerce_customer_billing" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-order:commerce-customer-billing" ],
            "field" : "field_sof_commerce_customer_type"
          }
        },
        { "data_is" : {
            "data" : [
              "commerce-order:commerce-customer-billing:field-sof-commerce-customer-type"
            ],
            "value" : "public"
          }
        }
      ],
      "DO" : [
        { "commerce_order_update_state" : { "commerce_order" : [ "commerce-order" ], "order_state" : "completed" } }
      ]
    }
  }');
  $items['commerce_payment_sof_dibs'] = entity_import('rules_config', '{ "commerce_payment_sof_dibs" : {
      "LABEL" : "Sof DIBS",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Payment" ],
      "REQUIRES" : [ "rules", "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "commerce_customer_billing" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-order:commerce-customer-billing" ],
            "field" : "field_sof_commerce_customer_type"
          }
        },
        { "NOT data_is" : {
            "data" : [
              "commerce-order:commerce-customer-billing:field-sof-commerce-customer-type"
            ],
            "value" : "public"
          }
        }
      ],
      "DO" : [
        { "commerce_payment_enable_commerce_dibs" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : "commerce_dibs"
          }
        }
      ]
    }
  }');
  $items['commerce_tax_rate_test'] = entity_import('rules_config', '{ "commerce_tax_rate_test" : {
      "LABEL" : "Calculate VAT",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Tax", "vat" ],
      "REQUIRES" : [ "commerce_tax" ],
      "USES VARIABLES" : { "commerce_line_item" : { "type" : "commerce_line_item", "label" : "Line item" } },
      "DO" : [
        { "commerce_tax_rate_apply" : {
            "USING" : {
              "commerce_line_item" : [ "commerce-line-item" ],
              "tax_rate_name" : "test"
            },
            "PROVIDE" : { "applied_tax" : { "applied_tax" : "Applied tax" } }
          }
        }
      ]
    }
  }');
  $items['rules_custom_send_mails_to_admin'] = entity_import('rules_config', '{ "rules_custom_send_mails_to_admin" : {
      "LABEL" : "Custom send mails to admin",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "rules", "message_notify", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "sof_order_admin_message",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-sof-message-order" ],
            "value" : [ "commerce-order" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } },
        { "message_notify_process" : {
            "message" : [ "entity-created" ],
            "save_on_fail" : 0,
            "save_on_success" : 0,
            "mail" : [ "site:mail" ]
          }
        }
      ]
    }
  }');
  $items['rules_custom_send_mails_to_user'] = entity_import('rules_config', '{ "rules_custom_send_mails_to_user" : {
      "LABEL" : "Custom send mails to user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "rules", "message_notify", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "commerce_customer_billing" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-order:commerce-customer-billing" ],
            "field" : "field_sof_commerce_customer_mail"
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "sof_order_user_message",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-sof-message-order" ],
            "value" : [ "commerce-order" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } },
        { "message_notify_process" : {
            "message" : [ "entity-created" ],
            "save_on_fail" : 0,
            "save_on_success" : 0,
            "mail" : [
              "commerce-order:commerce-customer-billing:field-sof-commerce-customer-mail"
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
