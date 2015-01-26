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
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "DO" : [
        { "commerce_payment_enable_commerce_dibs" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : "commerce_dibs"
          }
        }
      ]
    }
  }');
  $items['commerce_payment_sof_invoice'] = entity_import('rules_config', '{ "commerce_payment_sof_invoice" : {
      "LABEL" : "Sof Invoice",
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
        { "data_is" : {
            "data" : [
              "commerce-order:commerce-customer-billing:field-sof-commerce-customer-type"
            ],
            "value" : "public"
          }
        }
      ],
      "DO" : [
        { "commerce_payment_enable_sof_invoice_payment" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : "sof_invoice_payment"
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
  $items['rules_sof_collecting_shipping_services_0_005'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_0_005" : {
      "LABEL" : "Sof collecting shipping services 0.005",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003C=",
            "value" : "0.005",
            "unit" : "kg"
          }
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_0_005"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_0_2'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_0_2" : {
      "LABEL" : "Sof collecting shipping services 0.2",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "0.005",
            "unit" : "kg"
          }
        },
        { "AND" : [
            { "commerce_physical_rules_order_weight_comparison" : {
                "commerce_order" : [ "commerce_order" ],
                "operator" : "\\u003C=",
                "value" : "0.2",
                "unit" : "kg"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_0_2"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_0_45'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_0_45" : {
      "LABEL" : "Sof collecting shipping services 0.45",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "0.2",
            "unit" : "kg"
          }
        },
        { "AND" : [
            { "commerce_physical_rules_order_weight_comparison" : {
                "commerce_order" : [ "commerce_order" ],
                "operator" : "\\u003C=",
                "value" : "0.45",
                "unit" : "kg"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_0_45"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_0_9'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_0_9" : {
      "LABEL" : "Sof collecting shipping services 0.9",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "0.45",
            "unit" : "kg"
          }
        },
        { "AND" : [
            { "commerce_physical_rules_order_weight_comparison" : {
                "commerce_order" : [ "commerce_order" ],
                "operator" : "\\u003C=",
                "value" : "0.9",
                "unit" : "kg"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_0_9"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_19'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_19" : {
      "LABEL" : "Sof collecting shipping services 19",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "9.6",
            "unit" : "kg"
          }
        },
        { "AND" : [
            { "commerce_physical_rules_order_weight_comparison" : {
                "commerce_order" : [ "commerce_order" ],
                "operator" : "\\u003C=",
                "value" : "19",
                "unit" : "kg"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_19"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_1_9'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_1_9" : {
      "LABEL" : "Sof collecting shipping services 1.9",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "0.9",
            "unit" : "kg"
          }
        },
        { "AND" : [
            { "commerce_physical_rules_order_weight_comparison" : {
                "commerce_order" : [ "commerce_order" ],
                "operator" : "\\u003C=",
                "value" : "1.9",
                "unit" : "kg"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_1_9"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_4_8'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_4_8" : {
      "LABEL" : "Sof collecting shipping services 4.8",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "1.9",
            "unit" : "kg"
          }
        },
        { "AND" : [
            { "commerce_physical_rules_order_weight_comparison" : {
                "commerce_order" : [ "commerce_order" ],
                "operator" : "\\u003C=",
                "value" : "4.8",
                "unit" : "kg"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_4_8"
          }
        }
      ]
    }
  }');
  $items['rules_sof_collecting_shipping_services_9_6'] = entity_import('rules_config', '{ "rules_sof_collecting_shipping_services_9_6" : {
      "LABEL" : "Sof collecting shipping services 9.6",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SOF" ],
      "REQUIRES" : [ "commerce_physical", "commerce_shipping" ],
      "ON" : { "commerce_shipping_collect_rates" : [] },
      "IF" : [
        { "commerce_physical_rules_order_weight_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "value" : "4.8",
            "unit" : "kg"
          }
        }
      ],
      "DO" : [
        { "commerce_shipping_rate_apply" : {
            "commerce_order" : [ "commerce_order" ],
            "shipping_service_name" : "weight_to_9_6"
          }
        }
      ]
    }
  }');
  return $items;
}
